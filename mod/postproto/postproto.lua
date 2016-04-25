module('Postproto', package.seeall)
--[[

使用服务器id代替sockfd，主要因为断线后sockfd会改变，srvid的话就不会变
不过要先建立srvid <=> sockfd的映射
POST(srvid, 'Login.login', uid)
--]]

--特殊的消息
local REGIST = 0

srvid2sockfd = srvid2sockfd or {
    --[srvid] = sockfd
}

sockfd2srvid = sockfd2srvid or {
    --[sockfd] = srvid
}

function dispatch(sockfd, proto, srvid, funcname, ...)
    if funcname == REGIST then
        srvid2sockfd[srvid] = sockfd
        sockfd2srvid[sockfd] = srvid
        log('srvid(%d) <=> sockfd(%d)', srvid, sockfd)
        return
    end
    local pats = string.split(funcname, '.')
    local mod = _G[pats[1]]
    if not mod then
        logerr('mod(%s) not found', pats[1])
        return
    end
    local func = mod[pats[2]]
    if not func then
        logerr('func(%s) not found', pats[1])
        return
    end
    log('[POST][RECV]srvid(%d).%s()', srvid, funcname)
    log(Json.encode({...}))
    func(srvid, ...)
    log('[POST][RECV]srvid(%d).%s() END', srvid, funcname)
end

_G['POST'] = function(srvid, funcname, ...)
    local sockfd = srvid2sockfd[srvid] 
    if not sockfd then
        logerr('srv is not connect srvid(%d)', srvid or 0)
        return
    end
    log('[POST][SEND]srvid(%d).%s()', srvid, funcname)
    log(Json.encode({...}))
    Srvproto.send(sockfd, Srvproto.POST_PROTO, Config.srvid, funcname, ...)
    log('[POST][SEND]srvid(%d).%s() END', srvid, funcname)
end

function regist(srvid, sockfd)
    srvid2sockfd[srvid] = sockfd
    sockfd2srvid[sockfd] = srvid
    log('srvid(%d) <=> sockfd(%d)', srvid, sockfd)
    --将自己的srvid告诉对方
    Srvproto.send(sockfd, Srvproto.POST_PROTO, Config.srvid, REGIST)
end

function unregist(sockfd)
    local srvid = sockfd2srvid[sockfd]
    if srvid then
        srvid2sockfd[srvid] = nil
    end
    return srvid
end
