module('Adminsrv', package.seeall)
--[[
--管理台
--通关这个端口可以调用服务器的函数
--]]

portfd = nil

function main()
    portfd = Port.create(Ae.main_loop())
    listen()
end

function ev_read(sockfd, reason)
    log('ev_read sockfd(%d)', sockfd)
    local err = Srvproto.dispatch(sockfd)
    if err then
        Port.close(portfd, sockfd)
    end
end

function ev_close(sockfd, host, port, reason)
    log('ev_close sockfd(%d) reason(%s)', sockfd, reason)
    local srvid = Postproto.unregist(sockfd)
end

function ev_accept(sockfd)
    log('accept a admin sockfd(%d)', sockfd)
end

function listen()
    log('listen on host(%s) port(%d)', _CONF.host, _CONF.port)
    Port.rename(portfd, "AdminSrv")
    if not Port.listen(portfd, _CONF.port) then
        error('listen fail')
    end
    Port.on_accept(portfd, 'Adminsrv.ev_accept')
    Port.on_close(portfd, 'Adminsrv.ev_close')
    Port.on_read(portfd, 'Adminsrv.ev_read')
end
