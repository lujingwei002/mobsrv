module('Eventdisp', package.seeall)

--[[
事件接口，其实不是太想用事件
Event.regist('login', on_login)
Event.dispatch('login', uid)
--]]

eventmap = eventmap or {
    --[event] = {callback, callback}
}

--注册
function regist(event, callback)
    if not eventmap[event] then
        eventmap[event] = {}
    end
    --检查相同的？
    for k, v in pairs(map) do
        if v == callback then
            logwarn('duplicate regist event(%d)', event)
            return
        end
    end
    table.insert(eventmap[event], callback)
end

--反注册
function unregist(event, callback)
    local map = eventmap[event]
    if not map then
        return
    end
    for k, v in pairs(map) do
        if v == callback then
            map[k] = nil
            break
        end
    end
end

--分发消息
function dispatch(event, ...)
    local map = eventmap[event]
    if not map then
        return
    end
    for _, func in pairs(map) do
        func(...)
    end
end
