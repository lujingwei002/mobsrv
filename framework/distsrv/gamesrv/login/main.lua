module('Login', package.seeall)

--临时
tmp_player_manager = tmp_player_manager or {}
player_manager = player_manager or {}
onlinenum = onlinenum or 0

function main()
--    Pbc.import_dir(Config.game_dir..'/'.._CONF.dbproto)
--    Evdisp.add_timer(global_timer, Config.game_srv.save_interval * 1000, "Login.timer_check")
end

--功能:进入服务器
function PLAYER_ENTER(srvid, uid)
    tmp_player_manager[uid] = srvid
    log('player enter uid(%d)', uid)
    POST(CentersrvSockfd, 'Login.PLAYER_ENTER', uid)
    log('player enter uid(%d)', uid)
end

--功能:退出服务器
function PLAYER_EXIT(srvid, uid)
    log('player exit uid(%d)', uid)
    local player = player_manager[uid]
    if not player then
        logerr('player out found uid(%d)', uid)
        POST(CentersrvSockfd, 'Login.PLAYER_EXIT', uid)
        return
    end
    player_logout(player)
end

--功能：可以上线
function PLAYER_PASS(srvid, uid)
    local player = player_manager[uid]
    if player then
        logerr('player online yet uid(%d)', uid)
        return
    end
    --开始加载数据
    POST(DbsrvSockfd, 'Dbsrv.GET', uid, 'Login.msg_db_srv_get_playerdata', unpack(_CONF.playerdata))
end

--功能:被顶号
function PLAYER_INSTEAD(srvid, uid)
    log('player exit uid(%d)', uid)
    --解锁
    tmp_player_manager[uid] = nil
    local player = player_manager[uid]
    if not player then
        logerr('player out found uid(%d)', uid)
        return
    end
    local msg = Pbc.msgnew('login.DISCONNECT') 
    msg.errno = 15
    Gatesrv.reply(player.srvid, uid, msg)
    player_logout(player)
end

--功能:登陆成功
--@player
function player_login(player)
    local msg = Pbc.msgnew('login.ENTER')
    local uid = player.uid
    local user = player.playerdata.user
    local last_login_time = user.last_login_time
    local rt, err = pcall(Player.init, player)
    if not rt then
        log(err)
    end
    user.last_login_time = os.time()
    Player.reply(player, msg)
end

--功能:下线
--player
function player_logout(player)
    local uid = player.uid
    local rt, err = pcall(Player.close, player)
    if not rt then
        logerr(err)
    end
    --保存数据
    local playerdata = player.playerdata
    local args = {}
    for table_name, msg in pairs(playerdata) do
        --是否有脏标志
        if true or msg:isdirty() then
            log('uid(%d).%s is dirty', uid, table_name)
            table.insert(args, table_name)
            table.insert(args, msg)
        else
            log('uid(%d).%s is clean', table_name)
        end
    end
    POST(DbsrvSockfd, 'Dbsrv.SET', uid, 'Login.msg_db_srv_set_playerdata', unpack(args)) 
end

--功能:保存数据dv_srv返回
--@msg db_srv.SET_REPLY
function msg_db_srv_set_playerdata(srvid, uid, result, ...)
    local player = player_manager[uid]
    if not player then
        logerr('player offline yet')
        return 
    end
    if result == 0 then
        logerr('save playerdata fail uid(%d)', uid)
        return
    end
    local playerdata = player.playerdata
    local user = playerdata.user
    local args = {...}
    for _, varname in pairs(args) do
        local msg = playerdata[table_name]
        --msg:setdirty(0)
    end
    --已经下线了
    for k, v in pairs(playerdata) do
        playerdata[k] = nil
    end
    player.playerdata = nil
    --释放数据
    player_manager[uid] = nil
    onlinenum = onlinenum - 1
    --通知gateway_srv下线
    POST(CentersrvSockfd, 'Login.PLAYER_EXIT', uid)
end


--功能:读取数据返回
--@uid 
--@user_tables {table_name = msg}
--@argback string
function msg_db_srv_get_playerdata(_, uid, result, ...) 
    --如果没有锁住
    local srvid = tmp_player_manager[uid]
    if not srvid then
        POST(CentersrvSockfd, 'Login.PLAYER_EXIT', uid)
        logerr('player is disconnect')
        return
    end
    local player = player_manager[uid]
    if player then
        player.srvid = srvid
        logerr('player is online yet')
        return
    end
    if result == 0 then
        POST(CentersrvSockfd, 'Login.PLAYER_EXIT', uid)
        logerr('load playerdata fail uid(%d)', uid)
        return
    end
    local playerdata = {}
    local args = {...}
    for index, varname in pairs(_CONF.playerdata) do
        playerdata[varname] = args[index]
    end
    log( '加载数据成功')
    --建立session
    local player = {
        srvid = srvid, 
        uid = uid,
        playerdata = playerdata,
        last_save_time = os.time(),
    }
    player_manager[uid] = player
    tmp_player_manager[uid] = nil
    onlinenum = onlinenum + 1
    local rt, err = pcall(player_login, player)
    if not rt then
        logerr(err)
        player_logout(player)
    end
end


--功能:定时保存玩家数据
function timer_check()
    local timenow = os.time()
    for uid, player in pairs(player_manager) do
        local playerdata = player.playerdata
        if timenow - player.last_save_time > _CONF.save_interval then
            local args = {}
            for table_name, msg in pairs(playerdata) do
                if true or msg:isdirty() then
                    log('uid(%d).%s is dirty', uid, table_name)
                    table.insert(args, table_name)
                    table.insert(args, msg)
                else
                    log('uid(%d).%s is clean', table_name)
                end
            end
            POST(DbsrvSockfd, 'Dbsrv.SET', uid, 'Login.msg_db_srv_set_playerdata', unpack(args)) 
            player.last_save_time = timenow
        end
    end
end
