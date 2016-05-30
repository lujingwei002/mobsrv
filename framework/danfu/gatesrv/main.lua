print('hello lua')

require('telnetsrv.telnetsrv')


function main()
    loop = Ae.create(10240)
    Telnetsrv.main()
    Ae.main(Ae.main_loop())
end
