module('Gamesrv', package.seeall)

portfd = nil

game_manager = game_manager or {
    --[srvid] = {srvid, srvname, time}
}

function test_hello(timerid)
    log('hello')
    log(timerid)
    return 1
end

function main()
    log('create port')
    portfd = Port.create(Ae.main_loop())
    listen()
    --local timerid = Timer.addtimer(Ae.main_loop(), 1000, 'Gamesrv.test_hello')
    --print(timerid)
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
    for srvid, game in pairs(game_manager) do
        if game.srvid == srvid then
            game_manager[srvid] = nil
            log('game disconnect srvname(%s)', game.srvname)
            break
        end
    end
end

function ev_accept(sockfd)
    log('accept a game sockfd(%d)', sockfd)
end

function listen()
    log('listen on host(%s) port(%d)', _CONF.host, _CONF.port)
    Port.rename(portfd, "GameSrv")
    if not Port.listen(portfd, _CONF.port) then
        error('listen fail')
    end
    Port.on_accept(portfd, 'Gamesrv.ev_accept')
    Port.on_close(portfd, 'Gamesrv.ev_close')
    Port.on_read(portfd, 'Gamesrv.ev_read')
end

--功能:game_srv上线
--@srvname 服务名称
function REGIST(srvid, srvname)
    if game_manager[srvid] ~= nil then
        logerr('%s is connected yet', srvname)
        return 
    end
    local srv = {
        srvid = srvid,
        srvname = srvname,
        time = os.time()
    }
    game_manager[srvid] = srv 
    log('a game regist srvname(%s)', srvname)
end
