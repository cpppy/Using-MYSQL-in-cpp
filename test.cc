#include <mysql/mysql.h>
#include <iostream>
#include <string>

// g++ test.cc -lmysqlclient -o test

// ------table design & add table(function) to database(ecsstest)--------
// mysql -D ecsstest -u root -p < function.sql
// mysql -u root -p ecsstest < function.sql
/* 
//---------function.sql------------------
create table function
(
	userid int unsigned not null auto_increment primary key,
	network char(4) not null,
	city char(8) not null,
	text char(20) null default "write a message"
);
//----------------------------------------
*/


using namespace std;

MYSQL mysql;
//database ecsstest; table function;


void insert() {
	string sql = "insert into function(userid,network,city,text) values(10005,'WIFI','suzhou','suibianshangwang')";
	mysql_query(&mysql,sql.c_str());
}

void update() {
	string sql = "update function set city = 'berkely' where userid = 10002";
	mysql_query(&mysql,sql.c_str());
}


void show() {
	string sql = "select * from function";
	mysql_query(&mysql,sql.c_str());
	MYSQL_RES *result = NULL;
	result = mysql_store_result(&mysql);
	
	// get num of rows
	int rowcount = mysql_num_rows(result);
	cout<<"num of rows in function is : " << rowcount <<endl;
	
	//get name of every values'type in table
	MYSQL_FIELD *field = NULL;
	int fieldcount = mysql_num_fields(result);
	for(int i=0;i<fieldcount;++i) {
		field = mysql_fetch_field_direct(result,i);
		cout<< field->name <<'\t';
	}
	cout<<endl;
	cout<<"---data below------"<<endl;
	
	//get details in each row (its what we really need!!!)
	MYSQL_ROW row = NULL;
	row = mysql_fetch_row(result);
	while(NULL!=row) {
		for(int i=0;i<fieldcount;++i) {
			cout<<row[i]<<'\t';
		}
		cout<<endl;
		cout<<"-------------"<<endl;
		row = mysql_fetch_row(result);
	}
		
	
}
	
	
	
int main() {
	//MYSQL mysql;
	// connect to mysql and choose database
	mysql_init(&mysql);
	cout<<"mysql is runnig !"<<endl;
	mysql_real_connect(&mysql,"localhost","root","ene","ecsstest",0,NULL,0);
	cout<<"database have been connected !"<<endl;
	
	show();
	
	//insert();
	//show();
	
	//update();
	//show();
	
	
	mysql_close(&mysql);
	
	
	return 0;
	
}
