
create table if not exists user
(
    uid 	        int not null comment '',
	uname 		    varchar(32) comment '',
    coin            int not null comment '',
    lastlogintime   int not null comment '',
    updatetime      int not null comment '',
    primary key(uid)
)ENGINE = MYISAM;
