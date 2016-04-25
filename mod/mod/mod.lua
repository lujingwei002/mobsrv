module('Mod', package.seeall)
--[[
usage:
Mod.load('scene')
Mod.reload('scene')
Mod.reload()
Mod.call('update')
--]]

search_path = {'.'}
mod_table = {}

function test()
    print('test')
end

function load(mod_path)
    local real_path = mod_path
    for _, root_path in pairs(search_path) do
        real_path = string.format('%s/%s', root_path, mod_path)
        if File.exists(real_path) then
            break
        end
    end
    local pats = string.split(mod_path, '/')
    local mod_name = pats[#pats]
    print(string.format('mod_path(%s) mod_name(%s)', mod_path, mod_name))
    local files = File.listdir(real_path)
    if not files then
        print(string.format('dir not exist %s!!!!!!!!!!!!!!!!!!!!!!!!', mod_path))
        return
    end
    for _, file in pairs(files) do
        if file.type == 'file' then
            local file_path = string.format('%s/%s', mod_path, file.name)
            local index = string.find(file_path, '.lua$')
            if index and index + 3 == string.len(file_path) then
                local require_path = string.sub(file_path, 1, index - 1)
                print(string.format('scan file(%s)', file_path))
                local mod = require(require_path)
            else
                print(string.format('ignore file(%s)!!!!!', file_path))
            end
        end
    end
    local mod = _G[string.cap(mod_name)]
    if not mod then
        print(string.format('mod(%s) not found, please check mod name!!!', mod_path))
        os.exit(1)
    end
    mod_table[#mod_table + 1] = mod
    mod.log = function(...) Log.log_(mod_name, ...) end
    mod.logerr = function(...) Log.error_(mod_name, ...) end
    mod.logmsg = function(...) Log.msg_(mod_name, ...) end
    mod.logwarn = function(...) Log.warn_(mod_name, ...) end
    return mod
end

function cap(str)
    return string.upper(string.sub(str, 1, 1))..string.sub(str, 2)
end

function reload(mod_path)
end

function call(func_name, ...)
    for _, mod in pairs(mod_table) do
        local func = mod[func_name]
        if func then
            func(unpack(arg))
        end
    end
end

_G['import'] = load
