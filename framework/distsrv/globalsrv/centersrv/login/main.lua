module('Login', package.seeall)

player_manager = player_manager or {
    --[uid] = {uid, srvname, srvid, time}
}

onlinenum = onlinenum or 0

function main()

end

--功能:某个玩家上线
--@uid 玩家uid
function PLAYER_ENTER(srvid, uid)
    local game = Gamesrv.game_manager[srvid]
    if not game then
        logerr('srvid is not found srvid(%d)', srvid)
        return
    end
    local player = player_manager[uid]
    local srvid = game.srvid
    if not player then
        log('player online uid(%d)', uid)
        --插入一条记录
        player = {
                uid = uid,
                srvname = game.srvname, 
                srvid = game.srvid,
                time = os.time(),
                }
        player_manager[uid] = player
        --通知可以上线
        POST(game.srvid, 'Login.PLAYER_PASS', uid)
        onlinenum = onlinenum + 1
    elseif player.srvid then
        log('player instead to from game(%s) to game(%s)', game.srvname, player.srvname)
        --通知这个服下线
        POST(player.srvid, 'Login.PLAYER_INSTEAD', uid, game.srvname)
        --记录下这个player的srv_name
        player.instead_srvid = game.srvid
    else
        logerr('srvname is not found srvname(%s)', game.srvname)
    end
end

--功能:某个玩家下线
--@uid 玩家uid
function PLAYER_EXIT(srvid, uid)
    local game = Gamesrv.game_manager[srvid]
    if not game then
        logerr('srvid is not found srvid(%d)', srvid)
        return
    end
    log('player offline uid(%d)', uid)
    local player = player_manager[uid]
    local srvid = game.srvid
    if not player then
        log('player is not online uid(%d)', uid)
        return
    end
    if player.srvid ~= game.srvid then
        logerr('player exit from a different game, srvid(%s) from srvid(%s)', player.srvid, game.srvid)
        return
    end
    player_manager[uid] = nil
    onlinenum = onlinenum - 1
    --顶人下线的
    local instead_srvid = player.instead_srvid
    if instead_srvid ~= nil then
        local game = Gamesrv.game_manager[instead_srvid]
        player.instead_srvid = nil
        local player = {
                uid = uid,
                srvname = game.srvname, 
                srvid = game.srvid,
                time = os.time(),
                }
        player_manager[uid] = player
        --通知可以上线
        POST(game.srvid, 'Login.PLAYER_PASS', uid)
        onlinenum = onlinenum + 1
    end
end
