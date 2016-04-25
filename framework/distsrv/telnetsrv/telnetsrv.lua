module('Telnetsrv', package.seeall)

portfd = nil

function main()
    portfd = Strport.create(Ae.main_loop())
    listen()
end

function ev_read(sockfd, str)
    log('ev_read sockfd(%d) str(%s)', sockfd, str)
    local fn = loadstring(str)
    if fn then
        fn()
    end
end

function ev_close(sockfd, host, port, reason)
    log('ev_close sockfd(%d) reason(%s)', sockfd, reason)
end

function ev_accept(sockfd)
    log('accept a game sockfd(%d)', sockfd)
end

function listen()
    log('listen on host(%s) port(%d)', _CONF.host, _CONF.port)
    Port.rename(portfd, "TelnetSrv")
    if not Port.listen(portfd, _CONF.port) then
        error('listen fail')
    end
    Port.on_accept(portfd, 'Telnetsrv.ev_accept')
    Port.on_close(portfd, 'Telnetsrv.ev_close')
    Port.on_read(portfd, 'Telnetsrv.ev_read')
end
