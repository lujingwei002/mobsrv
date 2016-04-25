require('libsrv')
print('asfsdaf')
System.test()
print('hello')
--[[
local files = Sys.listdir('.')
for _, file in pairs(files) do
    print(file.name)
end
--]]
--
for i = 1, 10000000 do
    System.test()
end
