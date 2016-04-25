module('Main', package.seeall)

function main()
    print('globalsrv main')
    require('proto')
    require('dbproto')
    require('globalsrv')
    local msg = Pbc.msgnew('account.LOGIN')
    print('account.LOGIN', msg)
    --[[
    local playerdata = dbproto.PlayerData:new()
    print('playerdata', playerdata)
    print('playerdata.uid', playerdata.uid)
    Item.add_item(playerdata, 1, 2)
    Item.del_item(playerdata, 1, 2)
    print('playerdata.uid', playerdata.uid)
    --]]
    Asyncsrv.mainloop()
end


