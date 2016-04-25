DbinitConf = {
    mysql_conf = {
        jxqy = {
            dbproto_dir = 'dbproto',
            host = '127.0.0.1', user = 'root', password = '',
            tables = {
                user = {class = 'dbproto.UserData'},
                task = {class = 'dbproto.TaskData', binary = true},
                achieve = {class = 'dbproto.AchieveData', binary = true},
                friend = {class = 'dbproto.FriendData', binary = true},
            },
        },
    },
}
