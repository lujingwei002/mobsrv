
create table if not exists task
(
    uid 	    int not null comment '',
    bin         blob comment '',
    updatetime  int not null comment '更新时间',
    primary key(uid)
)ENGINE = MYISAM;
