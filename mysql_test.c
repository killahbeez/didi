#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{  
	MYSQL *con = mysql_init(NULL);

	if (con == NULL) {
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", "root", "dune", "mysql", 0, NULL, 0) == NULL) {
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	printf("Connection to mysql succesfully\n");

	if(mysql_query(con, "SELECT Host, User, Password FROM user")){
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}

	MYSQL_RES *res = mysql_store_result(con);
	if(!res){
		fprintf(stderr, "%s\n", mysql_error(con));
		exit(1);
	}

	printf("Number of rows: %d\n",(int) res->row_count);
	printf("Number of fields: %d\n",(int) res->field_count);
	MYSQL_ROW row;
	while ((row = mysql_fetch_row(res)))
	{
		printf("%s\t%s\t%s\n", row[0], row[1], row[2]);
	}


	mysql_free_result(res);

	mysql_close(con);
	exit(0);
}
