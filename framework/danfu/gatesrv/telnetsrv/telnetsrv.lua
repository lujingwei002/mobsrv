module('Telnetsrv', package.seeall)

portfd = nil

function on_read(sockfd, str)
    print('on_read', str)
end

function on_accept(sockfd, ip, port)
    print('on_accept', sockfd, ip, port)
end

function main()
    portfd = Strport.create(Ae.main_loop())
    Port.on_accept(portfd, 'Telnetsrv.on_accept')
    Port.on_read(portfd, 'Telnetsrv.on_read')
    Port.listen(portfd, 3333)
end
