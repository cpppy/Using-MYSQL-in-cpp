create table function
(
	userid int unsigned not null auto_increment primary key,
	network char(4) not null,
	city char(8) not null,
	text char(20) null default "write a message"
);
