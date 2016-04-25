module('Xmlsrv', package.seeall)

--侦听socket
sock_listen = nil

socket_manager = {}

local reply = [[<?xml version="1.0"?>
<!DOCTYPE cross-domain-policy SYSTEM "/xml/dtds/cross-domain-policy.dtd">
<!-- Policy file for xmlsocket://socks.example.com -->
<cross-domain-policy> 
<!-- This is a master socket policy file -->
<!-- No other socket policies on the host will be permitted -->
<!--site-control permitted-cross-domain-policies="all"/-->
<!-- Instead of setting to-ports="*", administrator's can use ranges and commas -->
<!-- This will allow access to ports 123, 456, 457 and 458 -->
<allow-access-from domain="*" to-ports="*" />
</cross-domain-policy>
]]

function ev_request(sockfd, str)
    logger:log(str)
    RawPort.send(sockfd, reply)
    Port.close(sock_listen, sockfd, '')
end

function post_msg(player, msg)
    PBPort.Send(player.sockfd,  msg)
end

function disconnect(player)
    Port.close(sock_listen, player.sockfd, 'server disconnect')
end

function ev_close(sockfd, reason)
    logger:log(string.format('client close from %s reason %s', Port.getpeerip(sockfd), reason))
    local player = socket_manager[sockfd]
    if player then
        socket_manager[sockfd] = nil
    end
end

function ev_accept(sockfd)
    logger:log('accept a client from '..Port.getpeerip(sockfd))
    socket_manager[sockfd] = {sockfd = sockfd, time = os.time()}
end

function listen()
    local xml_srv = _CONF.xml_srv
    logger:log('listen on '..xml_srv.host..':'..xml_srv.port)
    sock_listen = RawPort.create()
    Port.rename(sock_listen, "ClientSrv")

    if not Port.listen(sock_listen, xml_srv.port) then
        error('listen fail '..xml_srv.port)
    end
    Port.on_accept(sock_listen, 'ClientSrv.ev_accept')
    Port.on_packet(sock_listen, 'ClientSrv.ev_request')
    Port.on_close(sock_listen,  'ClientSrv.ev_close')
end

function timer_check()
    local timenow = os.time()
    for sockfd, player in pairs(socket_manager) do
        if timenow - player.time >= _CONF.tmp_sock_idle_interval then
            Port.close(sock_listen, sockfd, 'idle too long')
        end
    end
    return _CONF.tmp_sock_idle_interval * 1000
end

function main()
    listen()
    Timer.AddTimer(_CONF.tmp_sock_idle_interval * 1000, "ClientSrv.timer_check")
end
