module('Strproto', package.seeall)
--[[
telnet协议，运行时处理一些系统命令, gm之类的
--]]

ERR = 0

function dispatch(sockfd)
    --填充recvbuf
    local buf = Recvbuf.getwptr(sockfd)
    local bufremain = Recvbuf.bufremain(sockfd)
    log('bufremain(%d)', bufremain)
    local recv = Socket.recv(sockfd, buf, bufremain)
    log('recv(%d)', recv)
    if recv == 0 then
        --peer close half connection
        return ERR
    end
    if recv == -1 then
        return
    end
    Recvbuf.wskip(sockfd, recv)
    --读buf
    local pos = Recvbuf.find(sockfd, '\r\n')
    if not pos then
        Log.log(TAG, 'data not enough')
        return
    end
    local str = Recvbuf.readbuf(sockfd, pos)
    log('recv str(%s)', str)
    Recvbuf.rskip(sockfd, 2)
    Recvbuf.buf2line(sockfd)
    local fn = loadstring(str)
    if fn then
        fn()
    end
    --reply(sockfd, str)
end

function reply(sockfd, str)
    local len = string.len(str) + 2
    local buf = Sendbuf.alloc(sockfd, len)
    local arfd = Ar.create(buf, len)
    local write = Ar.writestr(arfd, str)
    Log.log(TAG, 'reply(%d)', write)
    local write = Ar.writestr(arfd, '\r\n')
    Log.log(TAG, 'reply(%d)', write)
    Sendbuf.flush(sockfd, buf, len)
    Ar.free(arfd)
    Port.add_write_event(sockfd)
end
