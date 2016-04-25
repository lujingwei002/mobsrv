moduel('Entity', package.seeall)

logger = Log.get_logger('Entity')

entity_table = {}


function find(entityid)
    return entity_table[entityid]
end


function insert(entityid, entity)
    if entity_table[entityid] then
        logger:error('eneity is dup entityid(%d)', entityid)
        return
    end
    entity_table[entityid, entity)
end

