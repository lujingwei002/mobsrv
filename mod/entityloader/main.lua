module('EntityLoader', package.seeall)

callbackid_inc = 1

callback_table = {}

--加载实体数据
function load(entityid, co)
    local callbackid = callbackid_inc
    callbackid_inc = callbackid_inc + 1
    callback_table[callbackid] = co
end

--保存数据
function save(entity, co)
    local callbackid = callbackid_inc
    callbackid_inc = callbackid_inc + 1
    callback_table[callbackid] = co
end

--实体数据返回
function rpc_load_return(callbackid, entity)
    local co = callback_table[callbackid]
    if not co then
        return
    end
    if type(co) == 'function' then
        co(entity)
    elseif type(co) == 'coroutine'
        coroutine.yield(entity)
    end
end

--保存数据返回
function rpc_save_return(callbackid, entity)
    local co = callback_table[callbackid]
    if not co then
        return
    end
    if type(co) == 'function' then
        co(entity)
    elseif type(co) == 'coroutine'
        coroutine.yield(entity)
    end
end
