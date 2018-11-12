/********************************************************************
* Author: Doug MacClure
* ZID: z0125061
* Class: CSCI466
* File: Assignment9: Querying a database in C++ from user input
********************************************************************/


#include <iostream>
#include <iomanip>
#include <mysql.h>
#include <stdio.h>
#include <string.h>


using namespace std;


int main()
{

//initialize SQL structures and pointers

MYSQL * conn, mysql;
MYSQL_RES * res;
MYSQL_ROW row;

int query_state;


//build the sql query
char sql[64] = {0};
char sqlquery1[1024] = "\" and Wrote.AuthorNum = Author.AuthorNum and Inventory.BookCode = Wrote.BookCode and Book.BookCode = Wrote.BookCode and Branch.BranchNum = Inventory.BranchNum and Publisher.PublisherCode = Book.PublisherCode ";

char sqlquery2[1024] = "select Book.Title, Publisher.PublisherName, Book.Type, Branch.BranchName, Inventory.OnHand from Author, Book, Branch, Inventory, Wrote, Publisher where Author.AuthorLast = \"";

//set connection and database variables

char * server = "students";
char * user = "z0125061";
char * password = "19810115";
char * database = "z0125061";

//connect to database
mysql_init(&mysql);
conn = mysql_real_connect(&mysql, server, user, password, database, 0,0,0);

//check connection
if (conn==NULL)

	{
	
	cout << mysql_error(&mysql) << endl;
	return 1;
	
	}

//get user input for query

cout << "Enter author's last name: ";
cin.getline(sql, 64);


//build query
strcat(sqlquery2, sql);
strcat(sqlquery2, sqlquery1);
const char * sqlquery = sqlquery1;

//send SQL query

query_state = mysql_query(conn, sqlquery2);


//check if query worked

if(query_state != 0)
	
	{
	
	cout << mysql_error(conn) << endl;
	return 1;
	
	}
	
//initialize row-by-row result set retrieval
res = mysql_store_result(conn);


//output result of query to user
cout << "Results of query:" << endl ;
cout << left << setw(25) << "Title" << setw(30) << "PublisherName" << setw(6) << "Genre" << setw(25) <<  "Branch Name" << setw(10) << "# On Hand" << endl;
cout << "---------------------------------------------------------------------------------------------------------" << endl;
while((row = mysql_fetch_row(res)) != NULL)

	{
	
	cout << left << setw(25) << row[0] << setw(30)  << row[1] << setw(6) << row[2] << setw(25) << row[3] << setw(10) << row[4] << endl;
	
	}

//free memory used by result set	
mysql_free_result(res);
//close connection
mysql_close(conn);


return 0;
}
