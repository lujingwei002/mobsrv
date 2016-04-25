module('Hoolaiclientsrv', package.seeall)

portfd = nil

socket_manager = socket_manager or {}
tmp_socket_manager = tmp_socket_manager or {}

function main()
    portfd = Port.create(Ae.main_loop())
    require(_CONF.protodir)
    local msg = Pbc.msgnew('account.LOGIN')
    assert(msg, 'proto not import')
    listen()
end

function ev_read(sockfd)
    log('ev_read sockfd(%d)', sockfd)
    local err = Hoolaiproto.dispatch(sockfd, dispatch)
    if err then
        log('something error')
        Port.close(portfd, sockfd)
    end
end

function dispatch(sockfd, msgbuf, msglen, msgname)
    log('dispatch msgname(%s)', msgname)
    local msg = Pbc.msgnew(msgname)
    msg:parse_from_buf(msgbuf, msglen)
    local pats = string.split(msgname, '.')
    local mod_name = pats[1]
    local func_name = pats[2]
    local timenow = os.time()
    local player = socket_manager[sockfd]
    --防止刷包
    if player then
        player.packet_counter = player.packet_counter + 1
        if player.packet_counter > _CONF.packet_count_threshold then
            if timenow - player.last_check_packet_time < _CONF.packet_time_threshold then
                logwarn('packet hack')
                local msg = pbc.msgnew('login.DISCONNECT')
                msg.errno = 14
                reply(player.sockfd,  msg)
                disconnect(player.sockfd, 'packet hack')
                return
            end
            player.last_check_packet_time = timenow
            player.packet_counter = 0
        end
    end
    --1.分发消息
    local mod = _G[string.cap(mod_name)]
    if mod then
        local func = mod['MSG_'..func_name]
        if func then
            func(player or sockfd, msg)
            return
        end
    end
    local route = _CONF.route[mod_name]
    route = route or _CONF.route[msgname]
    --2.分发消息到gamesrv
    if player and player.srvid and not route then
        Gameclient.forward(player.srvname, player.uid, msg)
        return
    end
    --3.分发消息到globalsrv
    if route then
        --末认证
        if route.need_auth and not player then
            logerr('not auth')
            return
        end
        local uid = player and player.uid or 0
        POST(route.srvid, 'Gatesrv.FORWARD', uid, msg)
        return
    end
end

function close(sockfd, reason) 
    Port.close(portfd, sockfd, reason);
end

function ev_close(sockfd, host, port, reason)
    log('ev_close sockfd(%d)', sockfd)
    local player = socket_manager[sockfd]
    if player then
        log('client close from uid(%d) ip(%s) reason(%s)', player.uid, host, reason)
        --保存数据 
        Login.player_disconnect(player)
        player.sockfd = nil
        socket_manager[sockfd] = nil
        return
    end
    if tmp_socket_manager[sockfd] then
        tmp_socket_manager[sockfd] = nil
    end
end

function ev_accept(sockfd, host, port)
    log('accept a client sockfd(%d) host(%s) port(%d)', sockfd, host, port)
    tmp_socket_manager[sockfd] = {time = os.time()}
end

function listen()
    log('listen on host(%s) port(%d)', _CONF.host, _CONF.port)
    Port.rename(portfd, "Clientsrv")
    if not Port.listen(portfd, _CONF.port) then
        error('listen fail')
    end
    Port.on_accept(portfd, 'Hoolaiclientsrv.ev_accept')
    Port.on_close(portfd, 'Hoolaiclientsrv.ev_close')
    Port.on_read(portfd, 'Hoolaiclientsrv.ev_read')
end

function update()
    --timer_check()
end

--功能:定时检测链接上来后, 没有发消息登陆的socket
function timer_check()
    local timenow = os.time()
    for sockfd, v in pairs(tmp_socket_manager) do
        local timebefore = v.time
        if timenow - timebefore > _CONF.tmp_sock_idle_sec then
            --太久没有验证成功的socket, 要关闭了
            Port.close(portfd, sockfd, 'tmp to long')
            log('tmp to long ip(%s)', Port.getpeerip(sockfd))
        end
    end
    return 1
end

function reply(sockfd, msg)
    Pbproto.send(sockfd, msg)
end
