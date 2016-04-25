module('Callproto', package.seeall)

--[[
    用协程实现的同步调用，上线项目末用过，
    必须在一个协议里面调用这个接口    
    local co = CALL(sockfd).VipSystem.dec_money(uid, 333)
    local result = yield co
    if result then
        Item.add_item(player, av, 333)
    end
--]]


callid_acc = callid_acc or 1

--回调表
--{[callid] = co}
callback_table = callback_table or {}


