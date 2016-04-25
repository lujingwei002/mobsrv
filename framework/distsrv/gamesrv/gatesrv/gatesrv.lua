module('Gatesrv', package.seeall)

portfd = port or nil

gate_manager = gate_manager or {
    --[srvid] = {srvid = srvid, srvname = srvname}
}

function main()
    Pbc.import_dir(Config.game_dir..'/'.._CONF.proto)
    portfd = Port.create(Ae.main_loop())
    listen()
end

function ev_read(sockfd)
    log('ev_read sockfd(%d)', sockfd)
    local err = Srvproto.dispatch(sockfd)
    if err then
        Port.close(portfd, sockfd)
    end
end

function reply(sockfd, uid, msg)
    POST(sockfd, 'Login.REPLY', uid, msg)
end

function ev_close(sockfd, reason)
    log('ev_close sockfd(%d) reason(%s)', sockfd, reason)
    local srvid = Postproto.unregist(sockfd)
    for _srvid, gate in pairs(gate_manager) do
        if _srvid == srvid then
            gate_manager[srvid] = nil
            log('gate disconnect srvname(%s)', gate.srvname)
            break
        end
    end
end

function ev_accept(sockfd)
    log('accept a gate sockfd(%d)', sockfd)
end

function listen()
    log('listen on host(%s) port(%d)', _CONF.host, _CONF.port)
    Port.rename(portfd, "Gatesrv")
    if not Port.listen(portfd, _CONF.port) then
        error('listen fail')
    end
    Port.on_accept(portfd, 'Gatesrv.ev_accept')
    Port.on_close(portfd, 'Gatesrv.ev_close')
    Port.on_read(portfd, 'Gatesrv.ev_read')
end

--功能:game_srv上线
--@srvname 服务名称
function REGIST(srvid, srvname)
    if gate_manager[srvid] ~= nil then
        logerr('game(%s) is connected yet', srvid)
        return 
    end
    local srv = {
        srvname = srvname,
        srvid = srvid,
        time = os.time()
    }
    gate_manager[srvid] = srv 
    log('a gate regist srvname(%s)', srvname)
end
