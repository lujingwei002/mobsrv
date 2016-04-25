module('Timer', package.seeall)

--[[
这个模块在系统定时器上做了一层封装，会跟随对象一起释放,不用担心释放的问题
local timerid = Timer.add_timer(player, 1000, hello)
Timer.stop_timer(player, timerid)
--]]

self_id_counter = 0
self_managers = {}

--弱表,比如player释放后，这里的引用会自动取消
setmetatable(self_managers, {__mode = 'v'})

--功能:todo({year = xxx}, 'xxx')
function todo(self, str, callback)
    --没有日期
    local expire_time = os.time(str) - os.time()
    expire_time = expire_time * 1000
    return add_timer(self, expire_time, callback)
end

function _init()
    Timer.setselftimerloop('Evdisp._on_self_timer')
end

--功能:为table增加一个timer, 
function add_timer(self, msec, callback)
    if self.tick_manager == nil then
        self.tick_manager = {}
        self_id_counter = self_id_counter + 1
        self.tick_self_id = self_id_counter
        self_managers[self_id_counter] = self
    end
    local timerid = Timer.add_self_timer(msec, self.tick_self_id)
    if timerid then
        self.tick_manager[timerid] = callback
    end
    return timerid
end

--功能:停止定时器
function stop_timer(self, timerid)
    Timer.stop_self_timer(timerid)
    if self.tick_manager then
        self.tick_manager[timerid] = nil 
    end
end

--功能:定时器回调
function _on_self_timer(timerid, selfid)
    local self = self_managers[selfid]
    if not self then
        --对象释放了，将定时器关闭
        return 0
    end
    for tid, callback in pairs(self.tick_manager) do
        if tid == timerid then
            local pats = string.split(callback, '.')
            local mod_name = pats[1]
            local func_name = pats[2]
            local rt = func(self)
            if not rt then
                self.tick_manager[timerid] = nil
            end
            return rt
        end
    end
    return 0
end
