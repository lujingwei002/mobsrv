
print('saf')
require('redis')
print('ccc')

local conn = Redis.connect('127.0.0.1', 6379)
print(conn)
local reply = Redis.command(conn, 'get 1')
print(reply)
for k, v in pairs(reply) do
    print(k, v)
end
Redis.close(conn)
print('safdsf')
