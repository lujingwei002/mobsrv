module('Asyncsrv', package.seeall)
--异步服务器
--服务器由数据包和定时器驱动

loop = loop or nil

function main()
    log('create loop')
    loop = Ae.create(10240)
end

_G['_atint'] = function()
    log('atint')
    Ae.stop(loop)
--    os.exit(0)
end

_G['_atexit'] = function()
    log('atexit')
    clearpid()
end

function clearpid()
    --清理pid
    local file = io.open('pid', 'r')
    if file then
        local pid = file:read()
        file:close()
        os.remove('pid')
        log('exit pid(%d)', pid)
    end
end

function recordpid()
    if File.exists('pid') then
        log('pid file exists')
        os.exit(1)
        return
    end
    local pid = System.getpid()
    local file = io.open('pid', 'w+')
    file:write(pid)
    file:close()
    log('running pid(%d)', pid)
end

function mainloop()
    --初始化环境
    Srvmain.main()
    --切换工作目录
    local running_dir = string.format('%s/%s', Config.proc_dir, Config.srvname)
    File.mkdirs(running_dir)
    File.chdir(running_dir)
    log('running dir(%s)', File.getcwd())
    if Config.daemon then
        Log.logfile(Config.srvname, 10000, running_dir)
        Srvmain.daemon()
    end
    recordpid()
    Ae.main(loop)
    log('game over!')
end

function add_timer(milliseconds, callback)
    Ae.create_time_event(Ae.main_loop(), milliseconds, 'Gamesrv.test')
end
