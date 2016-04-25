module('Wget', package.seeall)
--[[
HttpClient.get('http://www.google.com')
HttpClient.post('http://www.google.com')
--]]

function request(url, params, method, timeout)
    if method == 'GET' then
        url = url..'?'
        for k, v in pairs(params) do
            url = url..string.format('%s=%s&', k, v)
        end
        return get(url, timeout)
    elseif method == 'POST' then
        return post(url, params, timeout)
    end
end

function post(url, params, timeout)
    local sockfd = Socket.create()
    local params = string.urlparse(url)
    local host = params.host or 'localhost'
    local port = params.port or 80
    local path = params.path or '/'
    local query_string = params.query_string or nil
    if query_string then
        path = string.format('%s?%s', path, query_string)
    end
    local is_connect = Socket.connect(sockfd, host, port)
    if is_connect then
        send(sockfd, host, path, string.format('POST %s HTTP1.1', path), {}, JSON.encode(params))
        Socket.close(sockfd)
    end
end

function get_json(url, timeout)
    local reply = get(url, timeout)
    if not reply then
        return nil
    end
    local json =  JSON.decode(reply)
    for k, v in pairs(json) do
        if tonumber(v) then
            json[k] = tonumber(v)
        end
    end
    return json
end

function get(url, timeout)
    local socket = Socket.create()
    local params = string.urlparse(url)
    local host = params.host or 'localhost'
    local port = params.port or 80
    local path = params.path or '/'
    local query_string = params.query_string or nil
    if query_string then
        path = string.format('%s?%s', path, query_string)
    end
    socket:settimeout(timeout)
    local is_connect = socket:connect(host, port)
    
    print('url', url)
    print('path', path)
    print('query_string', query_string)
    if is_connect then
        local reply = send(socket, host, path, string.format('GET %s HTTP/1.1', path), {string.format('Host: %s', host)})
        socket:close()
        return reply
    end
end


function send(socket, host, path, req_line, headers, body)
    local msg = ''
    local absolute_path = host..path
    headers = headers or {}
    if body then
        table.insert(headers, string.format('Content-Length: %d', string.len(body)))
    end
    msg = msg..req_line
    msg = msg..'\r\n'
    if headers then
        for _, header in pairs(headers) do
            msg = msg..header
            msg = msg..'\r\n'
        end
    end
    msg = msg..'\r\n'
    if body then
        msg = msg..body
    end
    msg = msg..'\r\n'
    print('=============REQUEST=======================')
    print(msg)
    socket:send(msg)
    local reply = socket:recv(1000)
    print(reply)

    local headers = HttpPort.split_string(reply, '\r\n')
    local body = nil
    if string.find(reply, '\r\n\r\n') then
        body = headers[table.getn(headers)]
    end
    print('=============REQUEST END========================')
    return body, headers
end
