module('Route', package.seeall)

--路由表
route_table = {
}

function find(entityid)
    return route_table[entityid]
end

function add_route(entityid, stubid)
    route_table[entityid] = stubid
end

function remove_route(entityid)
    route_table[entityid] = nil
end

function clear()
    route_table = {}
end
