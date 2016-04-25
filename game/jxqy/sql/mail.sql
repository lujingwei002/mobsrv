
create table if not exists mail
(
	id 	        int not null auto_increment comment '',
    uid         int not null comment 'uid',
	uname       varchar(32) comment '用户名',
    title       varchar(64) comment '标题',
    text        varchar(128) comment '正文',
    senderuid   int not uull comment '',
    senderuname varchar(32) comment '',
    updatetime  int not null comment '',
    primary key(id)
)ENGINE = MYISAM;
