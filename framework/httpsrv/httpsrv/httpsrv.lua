module('Httpsrv', package.seeall)
ext_cfg = {
    ['ico'] = 'image/png',
    ['png'] = 'image/png',
    ['jpg'] = 'image/png',
    ['jpeg'] = 'image/png',
    ['css'] = 'text/css',
    ['html'] = 'text/html',
    ['js'] = 'text/javascript',
}
local slt2 = require('include/slt2')
--redis连接
local session_redis = nil
--生成sid的累加器
local session_acc = 0
--[[
回复有两种模式
1.在回复第一条内容的时候, 将headers发送出去
2.将回复前确定将全部内容缓存起来, 等所有内容准备好后, 将header和内容一起发送出去
默认是第2种模式
--]]

logger = Logger.get_logger('Http')
--侦听socket
sock_listen = nil

socket_manager = {}

http_cfg = {
    template_dir = '',

    recv_buf = 2048,
    tmp_sock_idle_interval = 10, --连上来后, 多久没有发消息过来, 则断开
    --防止刷包
    packet_count_threshold = 100,
    packet_time_threshold = 40,
    domain = 'taocpp.com',
    expires = 3600,
    --路由
    route = {
        ['/favicon.ico'] = '/static',
        ['/%w+%.css'] = '/static',
    },
    session = {
        secret = '19860701',
        expires = 3600,
        host = redis_host, dbname = '0', port = 6666, password = redis_password,
    },
    --图片目录
    image_dir = '/home/ljw/image/orgin',
    image_cache_dir = '/home/ljw/image/cache',
}

HEADERS = {
    ['Server'] = 'Kabu-Studio',
    ['Content-Type'] = 'text/html;charset=utf-8',
}

function ev_request(sockfd, str)
    local player = socket_manager[sockfd]
    if player.content_length and player.content_length > 0 then
        player.body = player.body..str
        player.content_length = player.content_length - string.len(str)
        if player.content_length <= 0 then
            local msg = player.msg
            local headers = msg.headers
            --处理消息体
            local content_type = headers['Content-Type']
            if content_type == 'application/x-www-form-urlencoded' then
                msg.post = HttpPort.decode_query_string(player.body)
                for k, v in pairs(msg.post) do
                    msg.post[k] = HttpPort.urldecode(v)
                end
            elseif string.find(content_type, 'multipart/form-data', 1, true) then
                parse_form_data(player, content_type, player.body)
            end
            --消息分发
            dispatch(player)
        end
        return
    end
    --拆headers
    local params = string.split(str, '\r\n')
    local request_line = params[1]
    params[1] = nil
    local pats = string.split(request_line, ' ');
    player.reply = {
        status_line = 'HTTP/1.1 200 OK',
        headers = {},
        body = '',
        cookie = {},
    }
    player.msg = {
        method = pats[1],
        uri = pats[2],
        version = pats[3],
        headers = {},
        arguments = {},
        query = '',
    }
    local msg = player.msg
    --分析header
    for _, v in pairs(params) do
        local pats = string.split(v, ': ')
        if pats[1] == 'Connection' then
            pats[2] = string.lower(pats[2])
        end
        msg.headers[pats[1]] = pats[2]
    end
    --分析uri
    local pats = string.split(msg.uri, '?')
    msg.path = pats[1]
    if pats[2] then
        msg.query = pats[2]
        msg.get = HttpPort.decode_query_string(pats[2])
        for k, v in pairs(msg.get) do
            msg.get[k] = HttpPort.urldecode(v)
            if tonumber(msg.get[k]) then
                msg.get[k] = tonumber(msg.get[k])
            end
        end
    else
        msg.get = {}
    end
    --分析cookie
    player.cookie = {}
    local cookie_str = msg.headers['Cookie']
    if cookie_str then
        player.cookie = HttpPort.kvparse(cookie_str)
    end
    --是否还有消息体
    if msg.headers['Content-Length'] then
        local content_length = tonumber(msg.headers['Content-Length'])
        player.content_length = content_length
        player.body = ''
        --return并等待body的到来
        HttpPort.content_length_mode(sockfd, content_length)
    else
        dispatch(player)
    end
end

--功能:重定向
function redirect(player, url)
    set_status_code(player, '302 Temporarily Moved')
    set_header(player, 'Location', url)
end
--功能:分析form-data
function parse_form_data(player, content_type, body)
    player.files = player.files or {}
    local splitid = '--'..string.sub(content_type, string.find(content_type, 'boundary=') + 9)
    player.files = decode_form_data(body, splitid)
    print(JSON.encode(player.files))
end

--功能:返回静态文件
function static_file(player, file_path)
    local app_dir = Config.app_dir
    local file_path = app_dir..file_path
    local file = io.open(file_path)
    local str = file:read('*a')
    file:close()
    local content_len = string.len(str)
    --找出文件后缀
    local ext = string.match(file_path, '%w+%.(%w+)')
    local content_type = ext_cfg[ext]
    content_type = content_type or 'image/png'
    set_content_type(player, content_type)
    set_content_length(player, content_len)
    local reply = player.reply
    reply.body = str
    _reply(player)
end

--功能:消息分发
function dispatch(player)
    local msg = player.msg
    print('request header', JSON.encode(msg))
    print('body', player.body)
    local path = msg.path
    --路由
    local route = http_cfg.route
    for pattern, rule in pairs(route) do
        if string.match(path, pattern) then
            if type(rule) == 'string' then
                static_file(player, rule..path)
                return
            end
        end
    end
    local mod_name = nil
    local action_name = nil
    local params = string.split(path, '/')
    if params[1] == '' then
        mod_name = params[2]
        action_name = params[3]
    else
        mod_name = params[2]
        action_name = params[3]
    end
    
    if mod_name and action_name then
        local func = _G[string.cap(mod_name)]['MSG_'..string.upper(action_name)]
        func(player, msg)
    else
        print('can not found handler')
    end
    _reply(player)
end

--功能:设置响应头
function set_status_code(player, str)
    local reply = player.reply
    reply.status_line = string.format('HTTP/1.1 %s\r\n', str)
end

--功能:设置消息体长度
function set_content_length(player, str)
    local reply = player.reply
    local headers = reply.headers
    headers['Content-Length'] = str
end

--功能:
function set_last_modified(player, time)
    set_header(player, 'Last-Modified', format_time(time))
end

--功能:设置消息体类型
function set_content_type(player, str)
    local reply = player.reply
    local headers = reply.headers
    headers['Content-Type'] = str
end

--功能:返回头
function get_header(player, k)
    local msg = player.msg
    local headers = msg.headers
    return headers[k]
end


--功能:设置回复头
function set_header(player, k, v)
    local reply = player.reply
    local headers = reply.headers
    headers[k] = v
end

--功能:获得cookie
function cookie_get(player, k)
    local cookie = player.cookie
    return cookie[k]
end

--功能:返回标准时间格式
function format_time(time)
    return os.strftime('%a, %d-%b-%Y %H:%m:%S %Z', time)
end
--功能:设置cookie
--@k
--@v
--@expires 秒
--@domain 
--@path
function cookie_set(player, k, v, expires, domain, path)
    local reply = player.reply
    local cookie = reply.cookie
    domain = domain or http_cfg.domain
    path = path or '/'
    expires = expires or (os.time() + http_cfg.expires)
    if not v then
        expires = 0
    end
    expires = format_time(expires)
    cookie[k] = string.format('%s=%s; Domain=%s; Path=%s; Expires=%s', k, v or '', domain, path, expires)
    --要不要设置到cookie里
    player.cookie[k] = v
end

--功能:返回json
function json(player, str)
    local reply = player.reply
    local body = reply.body
    reply.body = body..JSON.encode(str)
end

--功能:返回模板
function render(player, file_path, args)
    local file = io.open(http_cfg.template_dir..file_path)
    local str = file:read('*a')
    local tmpl = slt2.loadstring(str)
    local body = slt2.render(tmpl, args)
    local reply = player.reply
    reply.body = body
end

--功能:返回字符串
function post(player, str)
    local reply = player.reply
    local body = reply.body
    reply.body = body..str
end

function _reply(player)
    local msg = player.msg
    local reply = player.reply
    local headers = reply.headers
    local sockfd = player.sockfd
    HttpPort.send(sockfd, reply.status_line)
    HttpPort.send(sockfd, '\r\n')
    --默认消息头
    for k, v in pairs(HEADERS) do
        if not headers[k] then
            headers[k] = v
        end
    end
    --要不要保持链接
    --如果是1.0, 则要收到keep-alive
    local keep_alive = false
    if msg.headers['Connection'] == 'close' then
        keep_alive = false
    elseif msg.headers['Connection'] == 'keep-alive' then
        keep_alive = true
    end
    if msg.version == 'HTTP/1.0' and msg.headers['Connection'] == 'keep-alive' then
        keep_alive = true
    end
    if keep_alive then
        headers['Connection'] = 'keep-alive'
    else
        headers['Connection'] = 'close'
    end
    --是否有json
    if reply.json then
        reply.body = JSON.encode(reply.json)
    end
    --消息体
    headers['Content-Length'] = string.len(reply.body)
    --发送消息头
    for k, v in pairs(headers) do
        HttpPort.send(sockfd, string.format('%s: %s\r\n', k, v))
    end
    --发送cookie
    local cookie = reply.cookie
    for k , v in pairs(cookie) do
        HttpPort.send(sockfd, string.format('Set-Cookie: %s\r\n', v))
    end
    HttpPort.send(sockfd, '\r\n')
    --发送消息体
    HttpPort.send(sockfd, reply.body)

    if not keep_alive then
        Port.close(sock_listen, sockfd)
    end
    print('cookie', JSON.encode(cookie))
    print('header', JSON.encode(headers))
end

--[[
session
1.首先服务端要生成一个sid, 以保证不会被客户端能够生成
2.sid必须是唯一的, 所以用(secret, os.time, 进程pid, 累加器)生成
3.uid不能作为sid, 因为uid是公开的, 所以必须sid->uid
4.session都是实时写redis, 后面考虑加入session_commit
5.利用domain可以做到跨域名使用session
--]]

--功能:开始使用session
--@expires 秒
--@domain
--@path
function session_start(player, expires, domain, path)
    local sid = player.cookie.sid
    if sid then
        return
    end
    expires = expires or (os.time() + http_cfg.session.expires)
    --生成sid
    local sid = os.md5(string.format('%s.%d.%d.%d', http_cfg.session.secret, os.time(), os.getpid(), session_acc))
    session_acc = session_acc + 1
    if type(domain) == 'table' then
        for _, _domain in pairs(domain) do
            cookie_set(player, 'sid', sid, expires, _domain, path)
        end
    else
        cookie_set(player, 'sid', sid, expires, domain, path)
    end
    --设置过期
    local reply = session_redis:hmset(sid, 'sid', sid)
    local reply = session_redis:command(string.format('EXPIREAT %s %d', sid, expires))
end

--功能:返回session
--@k 
function session_get(player, k)
    local sid = player.cookie.sid
    if not sid then
        return nil
    end
    local reply = session_redis:command(string.format('HMGET %s %s', sid, k))
    if reply.type == Redis.ARRAY then
        local v = reply.value[1] 
        if v.type == Redis.STRING then
            return v.value
        end
    end
    return nil
end

--功能:设置session
--@k
--@expires 过期(单位:s)
function session_set(player, k, v)
    local sid = player.cookie.sid
    if not sid then
        return false
    end
    local reply = session_redis:hmset(sid, k, v)
    return true
end


--功能:清空session
function session_destory(player, domain, path)
    local sid = player.cookie.sid
    if not sid then
        return
    end
    cookie_set(player, 'sid', nil, -1, domain, path)
    --destory redis
    local reply = session_redis:command(string.format('DEL %s', sid))
end

--功能:链接session
function session_connect()
    local session_cfg = http_cfg.session
    session_redis = Redis.connect(session_cfg.host, session_cfg.port, session_cfg.password, session_cfg.dbname)
    logger:log('connect to session OK')
end

function ev_close(sockfd, reason)
    logger:log('close a client from '..Port.getpeerip(sockfd))
    socket_manager[sockfd] = nil
end

function ev_accept(sockfd)
    logger:log('accept a client from '..Port.getpeerip(sockfd))
    socket_manager[sockfd] = {sockfd = sockfd, time = os.time()}
end

function listen(host, port)
    logger:log('listen on '..host..':'..port)
    sock_listen = HttpPort.create()
    Port.rename(sock_listen, "ClientSrv")
    Port.set_recv_hm(sock_listen, http_cfg.recv_buf)

    if not Port.listen(sock_listen, port) then
        return false
    end
    Port.on_accept(sock_listen, 'Http.ev_accept')
    Port.on_packet(sock_listen, 'Http.ev_request')
    Port.on_close(sock_listen,  'Http.ev_close')

    return true
end

--功能:定时检测链接上来后, 没有发消息登陆的socket
function timer_check()
    return 1
end

function main(cfg)
    table.update(http_cfg, cfg)
    http_cfg.template_dir = Config.mod_dir
    print(JSON.encode(http_cfg))
    listen(http_cfg.host, http_cfg.port)
    session_connect()
end
