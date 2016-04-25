module('Main', package.seeall)

function main()
    print('gamesrv main')
    require('proto')
    require('dbproto')
    require('gamesrv')
    require('conf/main')
    print('itempoolconf', Conf.ItemPoolConf)
    Item.load_conf()
    Item.print_conf()
    local playerdata = Pbc.msgnew('dbproto.PlayerData')
    print('playerdata', playerdata)
    print('playerdata.uid', playerdata.uid)
    Item.add_item(playerdata, 1, 2)
    Item.del_item(playerdata, 1, 2)
    local msg = Pbc.msgnew('account.LOGIN')
    print('account.LOGIN', msg)
    Asyncsrv.mainloop()
end
