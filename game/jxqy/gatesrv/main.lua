module('Main', package.seeall)


function main()
    print('gatesrv main')
    require('proto')
    require('dbproto')
    require('gatesrv')
    Asyncsrv.mainloop()
end
