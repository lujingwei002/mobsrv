module('Argparse', package.seeall)
--[
-- xx -x y --x=y
-- Argparse.add_arg('x')
-- Argparse.parse_argv()
-- local x = Argparse.get_arg('x')
--]]

local arg_array = {}
local arg_map = {}

function parse_argv(args)
    local nextkey = nil
    for _, str in ipairs(args) do
        if string.find(str, '%-%-') then
            local index = string.find(str, '=')
            local key = string.sub(str, 3, index - 1)
            local val = string.sub(str, index + 1)
            arg_map[key] = val
        elseif string.find(str, '%-') then
            nextkey = string.sub(str, 2)
        elseif nextkey then
            local key = nextkey
            local val = str
            nextkey = nil
            arg_map[key] = val
        else
            table.insert(arg_array, str)
        end
    end
end

function get_arg(varname)
    return arg_array[varname] or arg_map[varname]
end

function get_arg_array()
    return arg_array
end

function test()
    parse_argv({'--cpp_out=hello', '-o', 'afaf', 'af', 'asfdaf'})
end
