
create table if not exists achieve
(
    uid 	    int not null comment '',
    bin         blob comment '',
    updatetime  int not null comment '',
    primary key(uid)
)ENGINE = MYISAM;

