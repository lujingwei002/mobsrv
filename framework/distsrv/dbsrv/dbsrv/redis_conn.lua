module('Dbsrv', package.seeall)

redis_table = redis_table or {}

function check_redis_connections()
    --关闭
    for index, info in pairs(redis_table) do
        local conf = _CONF.redis_conf[index]
        if not conf or conf.host ~= info.host or conf.port ~= info.port or conf.dbname ~= info.dbname then
            log('close redis connection index(%d) host(%s) port(%d) dbname(%s)', index, conf.host, conf.port, conf.dbname)
            Redis.close(info.redis)
            redis_table[index] = nil
        end
    end
    --连接
    for index, conf in pairs(_CONF.redis_conf) do
        if not redis_table[index] then
            local conn = Redis.connect(conf.host, conf.port)
            if not conn then
                log('fail connect redis index(%d) host(%s) port(%d) dbname(%s)', index, conf.host, conf.port, conf.dbname)
                redis_table[index] = nil
            else
                log('success connect redis index(%d) host(%s) port(%d) dbname(%s)', index, conf.host, conf.port, conf.dbname)
                redis_table[index] = {conn = conn, host = conf.host, port = conf.port, dbname = conf.dbname}
            end
        end
    end
end

function select_redis_connection(uid)
    local index = math.fmod(uid, #redis_table) 
    local info = redis_table[index + 1]
    return info and info.conn or nil
end

function ping_redis(conn)
    local reply = Redis.command(conn, 'ping')
    if not reply or reply.value ~= 'PONG' then
        for index, info in pairs(redis_table) do
            if info.conn == conn then
                Redis.close(info.conn)
                redis_table[index] = nil
                log('ping fail, close redis connection index(%d) host(%s) port(%d) dbname(%s)', index, conf.host, conf.port, conf.dbname)
                break
            end
        end
    end
end
