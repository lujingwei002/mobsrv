module('Login', package.seeall)

function login(player)
    Test.connect(player)
    Test.send(player, 'login.LOGIN', {uid = player.uid, params = '3333'})
    local reply = Test.recv(player, 'login.LOGIN')
    Test.send(player, 'login.ENTER', {})
    local reply = Test.recv(player, 'login.ENTER')
end

function ping(player)
    login(player)
    Test.send(player, 'login.PING', {})
    Test.recv(player, 'login.PING')
end

