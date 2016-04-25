require('mysql')

local conn = Mysql.connect('127.0.0.1', 'mysql', 'root', '')
print(conn)
local result = Mysql.select(conn, 'select user,host from user')
for i, row in pairs(result) do
    local str = ''
    for k, v in pairs(row) do
        str = str..string.format('%s=%s\t\t', k, v)
    end
    print(str)
    print()
end
Mysql.close(conn)
