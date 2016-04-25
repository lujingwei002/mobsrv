--[[

ItemConfPool *itemConfPool = new ItemConfPool();
itemConfPool->load("xxx");

--]]

require('actordb')
print('mod', Actordb)
local msg = Actordb.new('User')
print('msg', msg)
print('UserClass', getmetatable(msg))
msg.uid = 333
print('uid', msg.uid)
msg.uname = 'ljw'
print('uname', msg.uname)
msg.task = nil
msg.task_array = nil
local task = msg.task
print('task', task)
print('add_task_array', msg:add_task_array())
print('count_task_array', msg:count_task_array())
print('get_task_array', msg:get_task_array(0))
local task = msg:get_task_array(0)
task.uid = 333
for i = 1, 10000000 do
    msg.uid = 1
end
print('task.uid', task.uid)
print('del_task_array', msg:del_task_array(0))
print('bytesize', msg:bytesize())
print('tostring', msg:tostring())
print('tostring.len', string.len(msg:tostring()))


