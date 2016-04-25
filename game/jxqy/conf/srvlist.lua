
local gatesrv_conf = {
    {'mod/asyncsrv'},
    {'mod/pbc'},
    {'mod/strproto'},
    {'mod/strproto'},
    {'mod/pbproto'},
    {'mod/hoolaiproto'},
    {'mod/srvproto'},
    {'mod/callproto'},
    {'mod/postproto'},
    {'framework/distsrv/gatesrv/clientsrv', 
        host = '0.0.0.0', port = 3331,
        tmp_sock_idle_sec = 10,
        packet_count_threshold = 10,
        packet_time_threshold = 10,
        check_interval = 120,
        protodir = 'proto',
        maxsock = 65536,
        route = {},
    },
    {'framework/distsrv/gatesrv/login'},
    {'framework/distsrv/gatesrv/gameclient',
        gamesrv_list = {
            {srvid = 1, host = '127.0.0.1', port = 3332},
        },
    },
}


local gamesrv_conf = {
    {'mod/asyncsrv'},
    {'mod/strproto'},
    {'mod/srvproto'},
    {'mod/postproto'},
    {'mod/callproto'},
    {'mod/pbc'},
    {'framework/distsrv/gamesrv/gatesrv',
        host = '0.0.0.0', port = 3332,
        proto = 'proto',
    },
    {'framework/distsrv/gamesrv/globalclient',
        globalsrv_list = {
            {srvid = 2001, host = '127.0.0.1', port = 3334},
        },
        namesrv = {
            CentersrvSockfd = 2001,
            DbsrvSockfd = 2001,
        },
    },
    {'framework/distsrv/gamesrv/login',
        dbproto = 'dbproto',
        save_interval = 3600,
        playerdata = {
            'user', 
            'task', 
            'achieve',
        },
    },
    {'framework/distsrv/gamesrv/player'},
    {'game/jxqy/gamesrv/item'},
}

local globalsrv_conf = {
    {'mod/asyncsrv'},
    {'mod/pbc'},
    {'mod/timer'},
    {'mod/strproto'},
    {'mod/srvproto'},
    {'mod/postproto'},
    {'mod/callproto'},
    {'framework/distsrv/dbsrv/dbsrv',
        expire_sec = 100,
        delay_write = false,
        dbproto = 'dbproto',
        redis_conf = {
            {dbname = '1', host = '127.0.0.1', port = 6379, password = ''},
        },
        mysql_conf = {
            {dbname = 'jxqy', host = '127.0.0.1', user = 'root', port = 3306, password = ''},
        },
        --结构表和对象的映射
        table_conf = {
            user = {class = 'dbproto.UserData'},
            task = {class = 'dbproto.TaskData', binary = true},
            achieve = {class = 'dbproto.AchieveData', binary = true},
        },
    },
    {'framework/distsrv/globalsrv/gamesrv',
        host = '0.0.0.0', port = 3334,
    },
    {'framework/distsrv/globalsrv/globalsrv',
        host = '0.0.0.0', port = 3333,
    },
    {'framework/distsrv/globalsrv/centersrv/login'},
    {'game/jxqy/globalsrv/guild'},
    {'game/jxqy/globalsrv/item'},
    {'game/jxqy/globalsrv/mailsrv'},
    {'framework/distsrv/telnetsrv', host = '0.0.0.0', port = 9999},
    {'mod/mysqlgroup',
        mysql_conf = {
            {dbname = 'jxqy', host = '127.0.0.1', user = 'root', port = 3306, password = ''},
        },
    },
}

local config = {
    {srvid = 1001, script_dir = 'gatesrv',      srvname = 'gatesrv1',   mod = gatesrv_conf},
    {srvid = 2001, script_dir = 'globalsrv',    srvname = 'globalsrv1', mod = globalsrv_conf},
    {srvid = 1,    script_dir = 'gamesrv',      srvname = 'gamesrv1',   mod = gamesrv_conf},
    {srvid = 2,    script_dir = 'gamesrv',      srvname = 'gamesrv2',   mod = gamesrv_conf},
    {srvid = 3,    script_dir = 'gaemsrv',      srvname = 'gamesrv3',   mod = gamesrv_conf},
}

return config

