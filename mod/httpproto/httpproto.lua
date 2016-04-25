module('HttpProto', package.seeall)

--拆包
function dispatch(sockfd)
    local buf = RecvBuff.rbuf(sockfd)
    local buflen RecvBuff.rlen(sockfd)
    local real_recv = Socket.recv(sockfd, buf, buflen)
    RecvBuff.rskip(sockfd)
    while true do
        if RecvBuff.buflen(sockfd) < 4 then
            break
        end
        local plen = RecvBuff.get_int(sockfd)
        if RecvBuff.buflen(sockfd) < plen then
            break
        end
        local msgname = RecvBuff.read_str(sockfd)
        local buf = RecvBuff.rbuf(sockfd)
        local buflen RecvBuff.rlen(sockfd)
        local msg = Protobuf.decode(msgname, buf, buflen)
        RecvBuff.rskip(sockfd, plen)
    end
end

function flush(sockfd)
    local rptr = SendBuff.rptr()
    local rlen = SendBuff.rlen()
    local sent = Socket.send(sockfd, rptr, rlen)
    SendBuff.rskip(sockfd, sent)
end


function send(sockfd, msg)
    local msgname = msg:msgname()
    local buflen = msg:buflen()
    local buf = SendBuff.alloc(sockfd, buflen)
    Pbc.write(msg, buf, buflen)
    SendBuff.append(sockfd, buf, buflen)
end

