require('pblua')
Pblua.mappath('', '')
Pblua.import('proto/login.proto')
local msg = Pblua.msgnew('login.ENTER')
msg.uid = 333
msg.params = '333'
print('msg', msg)
print('msg.uid', msg.uid)
print('debug_string', Pblua.debug_string(msg))
print('bytesize', Pblua.bytesize(msg))
local t = Pblua.totable(msg)
print(t.uid)
print('over')
print(msg:tostring())

for i = 1, 10000000 do
    t.uid = i
end
print(t.uid)
print('adsaf')
