module('Mysqlhelper', package.seeall)

--功能：插入数据
function get(conn, table_name, conds)
    local sql = string.format('SELECT * FROM %s', table_name)
    if conds then
        local first = true
        local str = 'WHERE '
        for k, v in pairs(conds) do
            if first then
                first = false
            else
                str = str..' AND '
            end
            if type(v) == 'string' then
                str = string.format("%s %s='%s'", str, k, Mysql.escape(conn, v))  
            else
                str = string.format("%s %s=%s", str, k, v)  
            end
        end
        sql = string.format('%s %s', sql, str)
    end
    log(sql)
    return Mysql.select(conn, sql)
end

--功能：插入数据
function insert(conn, table_name, object)
    local str1 = string.format('INSERT INTO %s (', table_name)
    local str2 = string.format('VALUES(')
    local first = true
    for k, v in pairs(object) do
        if first then
            first = false
        else
            str1 = str1..','
            str2 = str2..','
        end
        str1 = str1..k
        if type(v) == 'string' then
            str2 = str2..'\''..Mysql.escape(conn, v)..'\''
        elseif type(v) == 'userdata' then
            str2 = str2..'\''..Mysql.escape(conn, v:tostring())..'\''
        else
            str2 = str2..v
        end
    end
    local sql = str1..') '..str2..')'
    log(sql)
    return Mysql.command(conn, sql)
end
