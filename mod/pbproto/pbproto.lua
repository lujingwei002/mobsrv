module('Pbproto', package.seeall)

--[[
2byte(packet len) + 2byte(seq) + 2byte(msgname len) + xbyte(msgname) + xbyte(msgbody)
--]]

--拆包
function dispatch(sockfd, callback)
    while true do
        local err, msgbuf, msglen, msgname = _decodebuf(sockfd)
        if err then
            return err
        end
        if not msgbuf then
            break
        end
        callback(sockfd, msgbuf, msglen, msgname)
    end
    Recvbuf.buf2line(sockfd)
end

--@return error, msgbuf, msglen, msgname
function _decodebuf(sockfd)
    local buf = Recvbuf.getrptr(sockfd)
    local bufremain = Recvbuf.bufremain(sockfd)
    local real_recv, err = Port.recv(sockfd, buf, bufremain)
    --log('real_recv(%d)', real_recv)
    if real_recv == -1 then
        return err
    end
    if real_recv == 0 then
        return
    end
    Recvbuf.wskip(sockfd, real_recv)
    --log('real_recv(%d) bufremain(%d)', real_recv, bufremain)
    local datalen = Recvbuf.datalen(sockfd) 
    if datalen < 2 then
        --log('header not enough(%d)', datalen)
        return
    end
    local plen = Recvbuf.getint16(sockfd)
    --log('plen(%d)', plen)
    if Recvbuf.datalen(sockfd) < plen then
        --log('data not enough(%d/%d)', datalen, plen)
        return
    end
    local arfd = Ar.create(buf, plen)
    local plen = Ar.readint16(arfd)
    local seq = Ar.readint16(arfd)
    local msgname = Ar.readlstr(arfd)
    local msgbuf = Ar.getptr(arfd)
    local msglen = Ar.remain(arfd)
    --log('plen(%d) seq(%d) msgname(%s) msglen(%d)', plen, seq, msgname, msglen)
    Ar.free(arfd)
    Recvbuf.rskip(sockfd, plen)
    return nil, msgbuf, msglen, msgname
end

function decode(sockfd)
    local err, msgbuf, msglen, msgname = _decodebuf(sockfd)
    if err then
        return err
    end
    if not msgbuf then
        return
    end
    --print(err, msgbuf, msglen, msgname)
    local msg = Pbc.msgnew(msgname)
    msg:parse_from_buf(msgbuf, msglen)
    log('[PB][RECV] msgname(%s)', msgname)
    return nil, msgname, msg
end

function send(sockfd, msg)
    local seq = 0
    local msgname = msg:msgname()
    local msglen = msg:bytesize()
    local plen = 2 + 2 + 2 + string.len(msgname) + msglen
    local buf = Sendbuf.alloc(sockfd, plen)
    local arfd = Ar.create(buf, plen)
    Ar.writeint16(arfd, plen)
    Ar.writeint16(arfd, seq)
    Ar.writelstr(arfd, msgname)
    msg:serialize(Ar.getptr(arfd))
    Sendbuf.flush(sockfd, buf, plen)
    Ar.free(arfd)
    Port.add_write_event(sockfd)
    log('[PB][SEND] plen(%d) msgname(%s) msglen(%d)', plen, msgname, msglen)
    return plen
end
