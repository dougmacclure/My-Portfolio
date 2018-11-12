
//Extra Credit Attempt


//Doug MacClure
//CSCI330-3
//Assignment 12
//TCP Server: Build a TCP server that is designed to handle multiple requests for directory access of a specified path.  
//Client is able to list directory contents and view file contents.

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

//helper function prototype
void processClientRequest( int, char *);
 
//we are expecting two command line arguments.  1: port # & 2: the pathname to a dir. that serves as root
//to all requested files or directories
 
int main(int argc, char *argv[]) {


	//check to make sure that we have the right # of command line arguments
	if (argc != 3) 
	{
	
		cerr << "USAGE: z0125061 port rootdirectory\n";
		exit(EXIT_FAILURE);
	
	}
	
	// Create the TCP socket 
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("Failed to create socket");
		exit(EXIT_FAILURE);
	}	
	
	// create address structures
	struct sockaddr_in direcserver;  // structure for address of server
	unsigned int serverlen = sizeof(direcserver);
	struct sockaddr_in direcclient;  // structure for address of client
	unsigned int clientlen = sizeof(direcclient);	
	
	// Construct the server sockaddr_in structure 
	memset(&direcserver, 0, sizeof(direcserver));       /* Clear struct */
	direcserver.sin_family = AF_INET;                   /* Internet/IP */
	direcserver.sin_addr.s_addr = INADDR_ANY;           /* Any IP address */
	direcserver.sin_port = htons(atoi(argv[1]));        /* server port */

	// Bind the socket
	serverlen = sizeof(direcserver);
	if (bind(sock, (struct sockaddr *) &direcserver, serverlen) < 0)
	{
	
		perror("Failed to bind server socket");
		exit(EXIT_FAILURE);
	
	}
	
	// listen: make socket passive and set length of queue
	if (listen(sock, 64) < 0) 
	{
	
		perror("listen failed");
		exit(EXIT_FAILURE);
	
	}
	
	// Run an infinite loop that accepts new client requests, and forks 
	// each request, so the child handles client request, and parent closes the
	//temp socket and handles next request ad infinitum
	while (true) 
	
	{
		//use accept system call to accept new client connections
		int connSock=accept(sock, (struct sockaddr *) &direcclient, &clientlen);
		
		//if a problem occurred with the accept, print error message and exit
		if (connSock < 0) 
		
		{
		
			perror("accept failed");
			exit(EXIT_FAILURE);
		
		}
		// fork
		if (fork()) 
			{// parent process
			
			close(connSock);
			
			} 
		else 
		{// child process
		
			processClientRequest(connSock, argv[2]);
		
		}
	}	
	//if while loop was cancelled, close socket before exiting program
	close(sock);
	return 0;
}

//****************************************************************************************
// FUNCTION: processClientRequest
// RETURNS:  void
// ARGUMENTS: int connSock, char *rootdir
// NOTES:  Handles client request.  Designed to give client access to specified root directory, and
// ability to list directory content and file content.
//****************************************************************************************

void processClientRequest( int connSock, char *rootdir) {
	
	//number of bytes received from client
	int received;
	
	//holdingspace for what client sent
	char command[257];
	//will hold the fullpath which we construct from the root(rootdir), and pathname sent by user
	char fullpath[256] = {0};
	
	char cat[] = "cat";
	char date[] = "date";
	char get[] = "GET";
	char list[] = "INFO";
	//initialize directory pointer
	DIR *dirp;
	//initialize struct dirent pointer
	struct dirent *dirEntry;
	//holds return status
	int rs;
	//initialize the stat struct to be used for checking if pathname refers to file
	struct stat buff;

	//read message from the client
	if ((received = read(connSock, command, 256)) <= 0) 
	
	{
	
		perror("Failed to receive message");
		exit(EXIT_FAILURE);
	
	}
	command[received] = 0;
	
	// duplicate socket descriptor into standard output so we can simply
	//cout to our client
	close(1);
	if (dup(connSock) < 0) 
		{
		
		perror("socket dup");
		exit(EXIT_FAILURE);
		
		}
	//do the same for standard error output, so perror sends error messages to client
	close(2);
	dup(connSock);
	
	if (dup(connSock) < 0) 
		{
		
		perror("socket dup");
		exit(EXIT_FAILURE);
		
		}
		
	//we are expecting the message to be of the form:
	//"GET pathname" or "LIST" so parse message by " "
	char *comname = strtok(command, " "); 
	//contains pathname
	char *pathname = strtok(NULL, " ");
	//everything after pathname is ignored

	//check if user simply wants to check current time and date
	if(strcmp(list, comname) == 0)
	
		{
		char *const argd[] = { date, (char*)NULL};
		rs = execvp("date", argd);
			
			if(rs == -1)
			
				{
					
				perror("date");
				exit(EXIT_FAILURE);	
					
				}
			
			
		exit(EXIT_SUCCESS);
				
		}

	
	if(pathname[0] != '/')
	
		{
		
		cout << "Error: " << command << " not found";
		exit(EXIT_FAILURE);
			
		}
			
	else
	
		{
			
	
							
		

		//check if comname == get
		if(strcmp(comname, get) != 0)
				{
				cout << "Error: improper command name. Usage: GET pathname";
				exit(EXIT_FAILURE);
				}
				
				
	
		//client gave wellformed pathname, so concatenate rootdir and pathname to get the true pathname
		//to be used with stat opendir and readdir
		strcat(fullpath, rootdir);
		strcat(fullpath, pathname);

		//check to make sure that ".." isn't within pathname before continuing
		for(unsigned i = 0; i < sizeof(fullpath); i++)
			
			{
			
			if(fullpath[i] == '.' && fullpath[i+1] == '.')
			
				{
				cout << "Error: cannot traverse backwards.";
				exit(EXIT_FAILURE);
					
				}
			
			}

	}
		
		
	

	//build stat structure buff
	
	rs = stat(fullpath, &buff);
	if (rs == -1)
	
		{
			
		perror("stat");
		exit(EXIT_FAILURE);
					
		}
		
	//using buff, check if fullpath is a file	
	if(S_ISREG(buff.st_mode))
	
		{
		//build double array which we use in execvp to list contents of file
		char *const argvp[] = { cat, fullpath, (char*)NULL};
		cout << "content of " << fullpath << ": " << endl;
		
		//list file contents
		rs = execvp("cat", argvp);
		if ( rs == -1)
		
			{
			
			perror("execvp");
			exit(EXIT_FAILURE);	
				
			}
			
		}
	
	
	//otherwise, fullpath is a directory
	else	
	
		{
			
		//open the directory with opendir
		dirp = opendir(fullpath);
		//if we couldn't, submit error message and exit
		if(dirp == 0)
	
			{
				perror(fullpath);
				exit(EXIT_FAILURE);
			
				
			}	
	
		//list directory content until NULL is met
		while((dirEntry = readdir(dirp)) != NULL)
	
			{
			
			cout << dirEntry->d_name << endl;
			
			}
			
		}
		
	close(connSock);
	//exit from helper function with good return status
	exit(EXIT_SUCCESS);
}
       
