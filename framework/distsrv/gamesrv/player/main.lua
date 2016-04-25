module('Player', package.seeall)


function reset(player)

end

function init(player)
    log('player init')
end

function close(player)
    log('player close')
end

function reply(player, msg)
    Gatesrv.reply(player.srvid, player.uid, msg)
end


