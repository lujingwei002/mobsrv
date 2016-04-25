module('Globalclient', package.seeall)

portfd = nil
socket_table = socket_table or {}

function main()
    portfd = Port.create(Ae.main_loop())
    Port.rename(portfd, "Globalclient")
    Port.on_close(portfd, 'Globalclient.ev_close')
    Port.on_connect_err(portfd, 'Globalclient.ev_connect_err')
    Port.on_connect_suc(portfd, 'Globalclient.ev_connect_suc')
    Port.on_read(portfd, 'Globalclient.ev_read')
    check_connections()
end

function ev_read(sockfd)
    log('ev_read sockfd(%d)', sockfd)
    local err = Srvproto.dispatch(sockfd)
    if err then
        Port.close(portfd, sockfd)
    end
end

function ev_connect_err(sockfd, host, port)
    socket_table[sockfd] = nil
    check_connections()
end

function ev_connect_suc(sockfd, host, port)
    log('ev_connect_suc sockfd(%d)', sockfd)
    local srvid = nil
    local globalsrv_list = _CONF.globalsrv_list
    for index, conf in pairs(globalsrv_list) do
        if conf.host == host and port == conf.port then
            srvid = conf.srvid
            break
        end
    end
    --别名
    for sockname, _srvid in pairs(_CONF.namesrv) do
        if _srvid == srvid then
            _G[sockname] = srvid  
            log('alias srvid(%d) to sockname(%s)', srvid, sockname)
        end
    end
    Postproto.regist(srvid, sockfd)
    POST(srvid, 'Gamesrv.REGIST', Config.srvname)
    --POST(srvid, 'Gamesrv.REGIST', Config.srvconf.srvname)
    --POST(srvid, 'Dbsrv.GET', 333, 'Globalclient.test_db_get', 'user')
end

function test_db_set(srvid, uid, result)
    log('test_db_set result(%d)', result)
end

function test_db_get(srvid, uid, result, msg)
    --log(msg)
    log('asfasf')
    log('uid(%d) result(%d)', uid, result)
    log('debug_string(%s)', msg:debug_string())
    POST(srvid, 'Dbsrv.SET', 333, 'Globalclient.test_db_set', 'user', msg) 
end

function ev_close(sockfd, host, port, reason)
    local srvid = Postproto.unregist(sockfd)
    log('ev_close sockfd(%d) reason(%s)', sockfd, reason)
    for sockname, _srvid in pairs(_CONF.namesrv) do
        if _srvid == srvid then
            _G[sockname] = nil
            log('del srvid(%d) to alias(%s)', srvid, sockname)
            break
        end
    end
    socket_table[sockfd] = nil
    check_connections()
end

--重连
function check_connections()
    local globalsrv_list = _CONF.globalsrv_list
    for sockfd, info in pairs(socket_table) do
        local find = false
        for index, conf in pairs(globalsrv_list) do
            if conf.host == info.host and conf.port == info.port then
                find = true
                break
            end
        end
        if not find then
            log('config changed!!')
            Port.close(portfd, sockfd, 'config changed')
        end
    end
    for index, conf in pairs(globalsrv_list) do
        local find = false
        for sockfd, info in pairs(socket_table) do
            if conf.host == info.host and conf.port == info.port then
                find = true
                break
            end
        end
        if not find then
            local sockfd = Port.connect(portfd, conf.host, conf.port)
            log('to connect sockfd(%d) host(%s) port(%d)', sockfd, conf.host, conf.port)
            if sockfd then
                socket_table[sockfd] = {sockfd = sockfd, host = conf.host, port = conf.port}
            end
        end
    end
end
