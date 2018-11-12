#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>



using namespace std;

int main() {
	
	
char empty[80] = {0};
char command1[80] = {0};
char subcom11[80] = {0}, subcom12[80] = {0}, subcom13[80] = {0}, subcom14[80] = {0}, subcom15[80] = {0};
char subcom21[80] = {0}, subcom22[80] = {0}, subcom23[80] = {0}, subcom24[80] = {0}, subcom25[80] = {0};
char command2[80] = {0};
char *argv1[] = {subcom11, subcom12, subcom13, subcom14, subcom15, (char*)NULL};
char *argv2[] = {subcom21, subcom22, subcom23, subcom24, subcom25, (char*)NULL};


char quit[] = "quit";
int pipefd[2], rs, pid, status, rs1, i, k;
//query user for input
	
cerr << "Enter command 1 (incl. args) or quit: ";
cin.getline(command1, 80);
if(strcmp(command1, quit)==0)

	exit(0);

cerr << "Enter command 2 (incl. args): ";
cin.getline(command2, 80);

for(i = 0; command1[i]!= ' ' && command1[i] != 0; i++)

	subcom11[i] = command1[i];

if(i<79 && command1[i] != 0)
{
k = i;
for(int j = i+1; command1[j]!= ' ' && command1[j] != 0; j++)

	{	
	subcom12[j- k -1] = command1[j];
	
	i++;
	}
}

if(i<79&& command1[i] != 0)

{
	
k = i;
for(int j = i +1 ; command1[j]!= ' ' && command1[j] != 0; j++)

	{

	subcom13[j - k -1] = command1[j];
	i++;
    }
	
}	
if(i<79&& command1[i] != 0)
{
	
k = i;
for(int j = i +1; command1[j]!= ' ' && command1[j] != 0; j++)

	{

	subcom14[j-k -1 ] = command1[j];
	i++;
		
	}
	
}
if(i<79&& command1[i] != 0)	

{
k = i;
for(int j = i +1; command1[j]!= ' ' && command1[j] != 0; j++)
	{

	subcom15[j-k -1] = command1[j];
	i++;
	}
}
for(i = 0; command2[i]!= ' ' && command2[i] != 0; i++)

	subcom21[i] = command2[i];
	
if(i<79&& command2[i] != 0)	

{
k=i;
for(int j = i +1; command2[j]!= ' ' && command2[j] != 0; j++)

	{

	subcom22[j-k -1 ] = command2[j];
	i++;
	
	}

}

if(i<79&& command2[i] != 0)

{
k = i;
for(int j = i +1 ; command2[j]!= ' ' && command2[j] != 0; j++)
	{

	subcom23[j-k-1] = command2[j];
	i++;
	
	}


}	
if(i<79&& command2[i] != 0)

{	
	k=i;
for(int j = i +1; command2[j]!= ' ' && command2[j] != 0; j++)

	{

	subcom24[j-k-1] = command2[j];
	i++;
	
	}

}
	
if(i<79&& command2[i] != 0)

{
	k=i;
for(int j = i +1 ; command2[j]!= ' ' && command2[j] != 0; j++)
	{

	subcom25[j-k-1 ] = command2[j];
	i++;

	}

}	


	strcpy(argv1[0], subcom11);
	
if(strcmp(empty, subcom12) != 0)
		strcpy(argv1[1], subcom12);
else
		argv1[1] = (char*)NULL;

if(strcmp(empty, subcom13) != 0)
	strcpy(argv1[2], subcom13);
	
else
	argv1[2] = (char*)NULL;

if(strcmp(empty, subcom14) != 0)
	strcpy(argv1[3], subcom14);
	
else
	argv1[3] = (char*)NULL;

if(strcmp(empty, subcom15) != 0)
	strcpy(argv1[4], subcom15);

else
	argv1[4] = (char*)NULL;


	strcpy(argv2[0], subcom21);

if(strcmp(empty, subcom22) != 0)
	strcpy(argv2[1], subcom22);

else
	argv2[1] = (char*)NULL;

if(strcmp(empty, subcom23) != 0)
	strcpy(argv2[2], subcom23);


else
	argv2[2] = (char*)NULL;
	
if(strcmp(empty, subcom24) != 0)	

	strcpy(argv2[3], subcom24);

else
	argv2[3] = (char*)NULL;

if(strcmp(empty, subcom25) != 0)
	strcpy(argv2[4], subcom25);
	
else

	argv2[4] = (char*)NULL;



rs = pipe(pipefd);
	if (rs == -1) 
	
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	
	}
	

	// fork into 2 processes

		//rs1 = fork(); 
		
/*
	if (rs1 == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	*/

while(true)

	{
	
	if(fork() == 0) {  // first child process	
		// close read end of pipe, keep write end open
		close(pipefd[0]);
		// close standard output so that the output of command goes 
		//"into" the current program
		close(1);
		// duplicate write end of pipe into standard output
		dup(pipefd[1]);
		// close write end of pipe
		close(pipefd[1]);
		// run command
		pid = execvp(argv1[0], argv1);
		//rs = system(command1);
	
		if (pid == -1)
		
			{
			perror("execvp");
			exit(EXIT_FAILURE);
			
			}
		
		}
		
	
/*
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}*/
	else if (fork() == 0)
		
		{ // second child process	
		// close write end of pipe, keep read end open
		
		close(pipefd[1]);
		// close standard input
		close(0);
		// duplicate read end of pipe into standard input
		dup(pipefd[0]);
		// close read end of pipe
		close(pipefd[0]);
	
	
		// run command
		cerr << "running command2";
		rs1 = execvp(argv2[0], argv2);
		
		//rs = system(command2);
		if (rs1 == -1)
		
		 {
			 
			perror("execvp");
			exit(EXIT_FAILURE);
		 }

		} 
		
	
	else //parent process
	
		{
		
		wait(&status);
		
		}
		//fflush(NULL);

		cerr << "Enter command 1 (incl. args) or quit: ";
		
		for(i = 0; i < 80; i++)
			{
			
			command1[i] = 0;
			command2[i] = 0;
			subcom11[i] = 0;
			subcom12[i] = 0;
			subcom13[i] = 0;
			subcom14[i] = 0;
			subcom15[i] = 0;
			subcom21[i] = 0;
			subcom22[i] = 0;
			subcom23[i] = 0;
			subcom24[i] = 0;
			subcom25[i] = 0;
					
			}
	/*	
	argv1[0] = (char*)NULL;
	argv1[1] = (char*)NULL;
	argv1[2] = (char*)NULL;
	argv1[3] = (char*)NULL;
	argv1[4] = (char*)NULL;
	argv2[0] = (char*)NULL;
	argv2[1] = (char*)NULL;
	argv2[2] = (char*)NULL;
	argv2[3] = (char*)NULL;
	argv2[4] = (char*)NULL;
*/
		cin.getline(command1, 80);	
		
		if(strcmp(command1, quit)==0)
			
			break;
	
		cerr << "Enter command 2 (incl. args): ";
		cin.getline(command2, 80);
		
for(i = 0; command1[i]!= ' ' && command1[i] != 0; i++)

	subcom11[i] = command1[i];

if(i<79 && command1[i] != 0)
{
k = i;
for(int j = i+1; command1[j]!= ' ' && command1[j] != 0; j++)

	{	
	subcom12[j- k -1] = command1[j];
	
	i++;
	}
}

if(i<79&& command1[i] != 0)

{
	
k = i;
for(int j = i +1 ; command1[j]!= ' ' && command1[j] != 0; j++)

	{

	subcom13[j - k -1] = command1[j];
	i++;
    }
	
}	
if(i<79&& command1[i] != 0)
{
	
k = i;
for(int j = i +1; command1[j]!= ' ' && command1[j] != 0; j++)

	{

	subcom14[j-k -1 ] = command1[j];
	i++;
		
	}
	
}
if(i<79&& command1[i] != 0)	

{
k = i;
for(int j = i +1; command1[j]!= ' ' && command1[j] != 0; j++)
	{

	subcom15[j-k -1] = command1[j];
	i++;
	}
}
for(i = 0; command2[i]!= ' ' && command2[i] != 0; i++)

	subcom21[i] = command2[i];
	
if(i<79&& command2[i] != 0)	

{
k=i;
for(int j = i +1; command2[j]!= ' ' && command2[j] != 0; j++)

	{

	subcom22[j-k -1 ] = command2[j];
	i++;
	
	}

}

if(i<79&& command2[i] != 0)

{
k = i;
for(int j = i +1 ; command2[j]!= ' ' && command2[j] != 0; j++)
	{

	subcom23[j-k-1] = command2[j];
	i++;
	
	}


}	
if(i<79&& command2[i] != 0)

{	
	k=i;
for(int j = i +1; command2[j]!= ' ' && command2[j] != 0; j++)

	{

	subcom24[j-k-1] = command2[j];
	i++;
	
	}

}
	
if(i<79&& command2[i] != 0)

{
	k=i;
for(int j = i +1 ; command2[j]!= ' ' && command2[j] != 0; j++)
	{

	subcom25[j-k-1 ] = command2[j];
	i++;

	}

}	
strcpy(argv1[0], subcom11);
	
if(strcmp(empty, subcom12) != 0)
		strcpy(argv1[1], subcom12);
else
		argv1[1] = (char*)NULL;

if(strcmp(empty, subcom13) != 0)
	strcpy(argv1[2], subcom13);
	
else
	argv1[2] = (char*)NULL;

if(strcmp(empty, subcom14) != 0)
	strcpy(argv1[3], subcom14);
	
else
	argv1[3] = (char*)NULL;

if(strcmp(empty, subcom15) != 0)
	strcpy(argv1[4], subcom15);

else
	argv1[4] = (char*)NULL;


	strcpy(argv2[0], subcom21);

if(strcmp(empty, subcom22) != 0)
	strcpy(argv2[1], subcom22);

else
	argv2[1] = (char*)NULL;

if(strcmp(empty, subcom23) != 0)
	strcpy(argv2[2], subcom23);


else
	argv2[2] = (char*)NULL;
	
if(strcmp(empty, subcom24) != 0)	

	strcpy(argv2[3], subcom24);

else
	argv2[3] = (char*)NULL;

if(strcmp(empty, subcom25) != 0)
	strcpy(argv2[4], subcom25);
	
else

	argv2[4] = (char*)NULL;
		

		
		rs = pipe(pipefd);
		if (rs == -1) 
			
			{
			perror("pipe");
			exit(EXIT_FAILURE);
			}
	
		cerr << "pipe created\n";
	
		//rs1 = fork();
		
		}

		
	return 0;	
	}	

