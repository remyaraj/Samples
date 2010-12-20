/*
 *  access a mysql database through c program
 */

#include <stdio.h>
#include <mysql.h>
#include <stdlib.h>

int main()
{
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char *server = "localhost";
   	char *user = "root";
   	char *password = "asdfgh"; /* set me first */
   	char *database = "information_schema";	

	conn = mysql_init(NULL);
	
	if(!mysql_real_connect(conn,server,user,password,database,0,NULL,0)){
		fprintf(stderr,"No connection Established");
		exit(1);
	}

	if(mysql_query(conn,"show tables")){
		fprintf(stderr,"sql query is not processed");
		exit(1);
	}

	res = mysql_use_result(conn);
	
	printf("The output is : \n");
	while((row = mysql_fetch_row(res))!=NULL){
		printf("%s\n",row[0]);
	}

	mysql_free_result(res);
	mysql_close(conn);
	

	return 0;
}
