module('Test', package.seeall)

local portfd = nil
local loop = nil

function connect(player)
    if not loop then
        loop = Ae.create(10240)
    end
    if not portfd then
        portfd = Port.create(loop)
        Port.rename(portfd, 'Test')
        Port.on_close(portfd, 'Test.ev_close')
        Port.on_read(portfd, 'Test.ev_read')
    end
end

function ev_read(sockfd, reason)
end

function ev_close(sockfd, host, port, reason)
    log('ev_close')
end

function send(player, msgname, params)
    local msg = Pbc.msgnew(msgname)
    for k, v in pairs(params) do
        msg[k] = v
    end
    local sockfd = player.sockfd
    if not sockfd then
        local conf = PbClientConf
        sockfd = Port.syncconnect(portfd, conf.host, conf.port)
        if not sockfd then
            logerr('connect fail')
            os.exit(1)
        end
        if sockfd < 0 then
            log('connect fail')
            os.exit(1)
        end
        player.sockfd = sockfd
    end
    Pbproto.send(sockfd, msg)
    log('send msg(%s) success', msg:msgname())
end

--接收消息
function recv(player, msgname)
    while true do
        Ae.run_once(loop)
        local _, msgname, msg = Pbproto.decode(player.sockfd)
        if  msg then
            log(string.format('recv msg name(%s)', msg:msgname())) 
            if msg:msgname() == msgname then
                log(msg:debug_string())
                return msg
            end
        end
    end
end
