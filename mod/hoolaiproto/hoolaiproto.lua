module('Hoolaiproto', package.seeall)

--[[
2byte(packet len) + 2byte(seq) + 2byte(msgname len) + xbyte(msgname) + xbyte(msgbody)
--]]

local err = 1

local stage_encry_req = 0
local stage_encry_ack = 1
local stage_tag = 2
local stage_communication = 3

local policy_req = '<policy-file-request/>';
local policy_resp = '<?xml version="1.0"?><cross-domain-policy><allow-access-from domain="*" to-ports="*"/></cross-domain-policy>';

--拆包
function dispatch(sockfd, callback)
    decode(sockfd)
    while true do
        local err, msgbuf, msglen, msgname = decode(sockfd)
        if err then
            return err
        end
        if not msgbuf then
            break
        end
        --callback(sockfd, msgbuf, msglen, msgname)
    end
    Recvbuf.buf2line(sockfd)
end

--@return error, msgbuf, msglen, msgname
function decode(sockfd)
    local bufremain = Recvbuf.bufremain(sockfd)
    local buf = Recvbuf.getrptr(sockfd)
    local real_recv, err = Port.recv(sockfd, buf, bufremain)
    log('real_recv(%d)', real_recv)
    if real_recv == -1 then
        return err
    end
    if real_recv == 0 then
        return
    end
    Recvbuf.wskip(sockfd, real_recv)
    if Port.getuserdata(sockfd) == stage_encry_req then
        local datalen = Recvbuf.datalen(sockfd)
        local buf = Recvbuf.getrptr(sockfd)
        local arfd = Ar.create(buf, datalen)
        local policy_req_len = Recvbuf.find(sockfd, policy_req)
        if policy_req_len then
            print('policy_req', policy_req_len)
            reply_policy_resp(sockfd, policy_resp)
            Recvbuf.rskip(sockfd, datalen)
        elseif Recvbuf.find(sockfd, 'tgw') then
            print('tgw')
            local lrcf =  Recvbuf.find(sockfd, '\r\n\r\n')
            if lrcf then
                print('skip tgw', lrcf + 4)
                Recvbuf.rskip(sockfd, lrcf + 4)
            end
        elseif datalen >= 4 then
            print('encrypt key')
            reply_salt(sockfd)
            Recvbuf.rskip(sockfd, datalen)
            Port.setuserdata(sockfd, stage_encry_ack)
        end
  --  print(Ar.readstr(arfd, real_recv))
        Ar.free(arfd)
    end
    if Port.getuserdata(sockfd) == stage_encry_ack then
        local datalen = Recvbuf.datalen(sockfd)
        if datalen >= 2 then
            local buf = Recvbuf.getrptr(sockfd)
            local arfd = Ar.create(buf, datalen)
            local crc = Ar.readint16(arfd)
            print('stage_encry_ack', crc)
            Ar.free(arfd)
            Recvbuf.rskip(sockfd, 2)
            Port.setuserdata(sockfd, stage_tag)
        end
    end
    if Port.getuserdata(sockfd) == stage_tag then
        local datalen = Recvbuf.datalen(sockfd)
        print('stage_tag datalen', datalen)
        if datalen >= 2 then
            local tag = Recvbuf.getuint16(sockfd)
            if tag == 52462 then
                Port.setuserdata(sockfd, stage_communication)
            end
            Recvbuf.rskip(sockfd, 2)
        end
    end
    if Port.getuserdata(sockfd) == stage_communication then
        local datalen = Recvbuf.datalen(sockfd)
        print('stage_communication datalen', datalen)
        if datalen >= 2 then
            local len = Recvbuf.getuint16(sockfd)
            print(string.format('len(%d) datalen(%d)', len, datalen))
            local plen = len + 6 --不是14吗
            if datalen >= plen then
                print('recv a packet')
                Recvbuf.rskip(sockfd, 6)
                local buf = Recvbuf.getrptr(sockfd)
                local arfd = Ar.create(buf, len)
                local cmd = Ar.readuint8(arfd)
                print('cmd', cmd)
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                print(Ar.readuint8(arfd))
                Ar.free(arfd)
                Recvbuf.rskip(sockfd, len)
                Port.setuserdata(sockfd, stage_tag)
            end
        end
    end
    --[[
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
    --]]
end
--[[
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
--]]
--

function reply_salt(sockfd)
    local buf = Sendbuf.alloc(sockfd, 4)
    local arfd = Ar.create(buf, 4)
    Ar.writeint32(arfd, 0)
    Sendbuf.flush(sockfd, buf, 4)
    Ar.free(arfd)
    Port.add_write_event(sockfd)
    log('[SEND] reply salt')
    return strlen

end

function reply_policy_resp(sockfd, str)
    local strlen = string.len(str) + 1
    local buf = Sendbuf.alloc(sockfd, strlen)
    local arfd = Ar.create(buf, strlen)
    Ar.writestr(arfd, str)
    Ar.writeint8(arfd, 0)
    Sendbuf.flush(sockfd, buf, strlen)
    Ar.free(arfd)
    Port.add_write_event(sockfd)
    log('[SEND] str strlen(%d) str(%s)', strlen, str)
    return strlen

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
