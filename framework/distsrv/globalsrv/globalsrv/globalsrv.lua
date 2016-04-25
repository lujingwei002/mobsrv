module('Globalsrv', package.seeall)

portfd = nil

global_manager = global_manager or {
    --[srvid] = {srvid, srvname, time}
}

function main()
    portfd = Port.create(Ae.main_loop())
    listen()
end

function ev_close(sockfd, host, port, reason)
    log('ev_close sockfd(%d) reason(%s)', sockfd, reason)
    local srvid = Postproto.unregist(sockfd)
    for srvid, global in pairs(global_manager) do
        if global.srvid == srvid then
            global_manager[srvid] = nil
            log('global disconnect srvname(%s)', global.srvname)
            break
        end
    end
end

function ev_read(sockfd)
    log('ev_read sockfd(%d)', sockfd)
    local err = Strproto.dispatch(sockfd)
    if err then
        Port.close(portfd, sockfd)
    end
end

function ev_accept(sockfd)
    log('accept a global sockfd(%d)', sockfd)
end

function listen()
    log('listen on host(%s) port(%d)', _CONF.host, _CONF.port)
    Port.rename(portfd, "GlobalSrv")
    if not Port.listen(portfd, _CONF.port) then
        error('listen fail')
    end
    Port.on_accept(portfd, 'Globalsrv.ev_accept')
    Port.on_close(portfd, 'Globalsrv.ev_close')
    Port.on_read(portfd, 'Globalsrv.ev_read')
end

--功能:globalsrv上线
--@srv_name 服务名称
function REGIST(srvid, srvname)
    if global_manager[srvid] ~= nil then
        logerr('%s is connected yet', srvname)
        return 
    end
    local srv = {
        srvid = srvid,
        srvname = srvname,
        time = os.time()
    }
    global_manager[srvid] = srv 
    log('a global regist srvname(%s)', srvname)
end
