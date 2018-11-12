

//Doug MacClure
//CSCI330-3
//Assignment 10
//Pipe Shell: Within a loop, query user for two commands which will be piped together, and resulting output will be printed to cout



#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>


//function prototypes
void fill_argvs();
void fill_args();
void clear();
void erase(char*);
int execute(char**);

//arrays are global for simplfying function calls

//temporary holding area for user input
char command1[80] = {0};
char command2[80] = {0};

//use these c-strings to partition input
char subcom11[80] = {0}, subcom12[80] = {0}, subcom13[80] = {0}, subcom14[80] = {0}, subcom15[80] = {0}, subcom16[80] = {0};
char subcom21[80] = {0}, subcom22[80] = {0}, subcom23[80] = {0}, subcom24[80] = {0}, subcom25[80] = {0}, subcom26[80] = {0};

//empty string used to check if another array is empty
char empty[80] = {0};

//copy above substrings into these double arrays, which need a special null terminator pointer
char *argv1[] = {subcom11, subcom12, subcom13, subcom14, subcom15, subcom16, (char*)NULL};
char *argv2[] = {subcom21, subcom22, subcom23, subcom24, subcom25, subcom26, (char*)NULL};

using namespace std;

int main() {
	
//use this array to compare against user input 
char quit[] = "quit";

//necssary file descriptors and process ids
int pipefd[2], rs, pid, rs1, chd1, chd2;

//query user for input
cerr << "Enter command 1 (incl. args) or quit: ";
cin.getline(command1, 80);

//if user wants to quit, exit program with good return status
if(strcmp(command1, quit)==0)
	exit(0);

//query again
cerr << "Enter command 2 (incl. args): ";
cin.getline(command2, 80);

//partition input into various substrings, where the field separator is whitespace
fill_args();

//fill our double arrays that are used in the execvp calls
fill_argvs();

//create a new pipe
rs = pipe(pipefd);

	//if we were unable to create a new pipe, exit with bad return status
	if (rs == -1) 
	
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	
	}
	

	// fork into 2 processes

	chd1 = fork(); 
		

	if (chd1 == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	

while(true)

	{
	
// first child process	
	
	if(chd1 == 0) 
	
		{  
		// close read end of pipe, keep write end open
		close(pipefd[0]);
		// close standard output so that the output of command goes 
		//"into" the current program
		close(1);
		// duplicate write end of pipe into standard output
		dup2(pipefd[1], 1);

		// close write end of pipe
		close(pipefd[1]);
		// run command
		
		//fflush(NULL);
		pid = execute(argv1);
	
		//if there was an error in the syntax of command1, we will catch it here
		if (pid == -1)
		
			{
			perror("execvp");
			exit(EXIT_FAILURE);
			
			}
		
		}
		
	

	

	
	else
	 	{
		
		//create 2nd child process
		chd2 = fork();
		
		//2nd child process
		if (chd2 == 0)
		
			{ 	
			// close write end of pipe, keep read end open
		
			close(pipefd[1]);
			// close standard input
			close(0);
			// duplicate read end of pipe into standard input
			dup2(pipefd[0], 0);
			// close read end of pipe
			close(pipefd[0]);
				
			// run command
		
			rs1 = execute(argv2);
		
			//if there was a syntax error in command2, we will catch it here
			if (rs1 == -1)
		
				{
			 
				perror("execvp");
				exit(EXIT_FAILURE);
				}

			} 
		
//parent process

	else
	
		{
			
		//close both ends of pipe in parent process, otherwise, result of children processes will not be printed
		//until after program exits
		close(pipefd[0]);
		close(pipefd[1]);
		
		//wait for both child processes to finish executing before continuing
		wait(NULL);
		wait(NULL);
		
		//clear all of our input arrays
		clear();
		
		//move on to next loop and query user for more input, offering an option to exit loop
		cerr << "Enter command 1 (incl. args) or quit: ";
		
		cin.getline(command1, 80);	
		
		if(strcmp(command1, quit)==0)
			
			break;
							
		cerr << "Enter command 2 (incl. args): ";
		cin.getline(command2, 80);
		
		//fill argument arrays with the various arguments listed in command1's & command2's fields separated by whitespace
		fill_args();
		
		//fill our double arrays which we use when we call exec to execute user-specified commands
		fill_argvs();

		//create a new pipe
		rs = pipe(pipefd);
		if (rs == -1) 
			
			{
			perror("pipe");
			exit(EXIT_FAILURE);
			}
	
		}
		
		//fork first child process, and restart while loop
			
		chd1 = fork();
	}
		

}	
	return 0;	
	

}

//****************************************************************************************
// FUNCTION: fill_argvs()
// RETURNS:  void
// ARGUMENTS: void
// NOTES:  This is where the "dirty work" of filling our exec-specific double array's with command 
// line argument maintenance is done.  Simple if-else logic is used to copy C-strings.
//****************************************************************************************

void fill_argvs()
{

//we are guaranteed to have something in subcom11--since it is the beginning of user input for command1
strcpy(argv1[0], subcom11);


//GENERAL LOGIC:

//if the next field in commandx array (subcomxy) is nonempty, copy field into y'th position of argvx
//else, make y'th position of argvx an empty string

if(strcmp(empty, subcom12) != 0)
		strcpy(argv1[1], subcom12);
else
	erase(argv1[1]);
	
if(strcmp(empty, subcom13) != 0)
	strcpy(argv1[2], subcom13);
	
else
	erase(argv1[2]);

if(strcmp(empty, subcom14) != 0)
	strcpy(argv1[3], subcom14);
	
else
	
	erase(argv1[3]);

//if the next field in commandx array (subcomxy) is nonempty, copy field into y'th position of argvx
//else, make y'th position of argvx an empty string

	
if(strcmp(empty, subcom15) != 0)
	strcpy(argv1[4], subcom15);

else
	erase(argv1[4]);


//basically repeat above logic for command2[] and argv2[][]

strcpy(argv2[0], subcom21);

if(strcmp(empty, subcom22) != 0)
	strcpy(argv2[1], subcom22);

else
	erase(argv2[1]);

//if the next field in commandx array (subcomxy) is nonempty, copy field into y'th position of argvx
//else, make y'th position of argvx an empty string


if(strcmp(empty, subcom23) != 0)
	strcpy(argv2[2], subcom23);


else

	erase(argv2[2]);
	
	
if(strcmp(empty, subcom24) != 0)	
	strcpy(argv2[3], subcom24);

else

		erase(argv2[3]);

//if the next field in commandx array (subcomxy) is nonempty, copy field into y'th position of argvx
//else, make y'th position of argvx an empty string


if(strcmp(empty, subcom25) != 0)
	strcpy(argv2[4], subcom25);
	
else


	erase(argv2[4]);

}


//****************************************************************************************
// FUNCTION: fill_args()
// RETURNS:  void
// ARGUMENTS: void
// NOTES:  This is where the "dirty work" of filling our argument arrays (subcom) with data 
// from initial user input arrays (command) is done.
//****************************************************************************************


void fill_args()

{
	
//index variables
int i = 0;
int k;

//loop through first field delimited by ' ' and copy over to subcom
for(i = 0; command1[i]!= ' ' && command1[i] != 0; i++)

	subcom11[i] = command1[i];

//if we still have more stuff one position after whitespace element we previously encountered

if(i<79 && command1[i] != 0)
{
	
//since we want to iterate i and j at the same time, we need a temporary index variable so we do not
//iterate subcom twice
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

//if we still have more stuff one position after whitespace element we previously encountered

if(i<79&& command1[i] != 0)
{
//since we want to iterate i and j at the same time, we need a temporary index variable so we do not
//iterate subcom twice	

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

//if we still have more stuff one position after whitespace element we previously encountered


if(i<79&& command1[i] != 0)	

//since we want to iterate i and j at the same time, we need a temporary index variable so we do not
//iterate subcom twice

{
k = i;
for(int j = i +1; command1[j]!= ' ' && command1[j] != 0; j++)
	{

	subcom16[j-k -1] = command1[j];
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

//if we still have more stuff one position after whitespace element we previously encountered


if(i<79&& command2[i] != 0)

//since we want to iterate i and j at the same time, we need a temporary index variable so we do not
//iterate subcom twice

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
	
//if we still have more stuff one position after whitespace element we previously encountered

	
if(i<79&& command2[i] != 0)

//since we want to iterate i and j at the same time, we need a temporary index variable so we do not
//iterate subcom twice

{
	k=i;
for(int j = i +1 ; command2[j]!= ' ' && command2[j] != 0; j++)
	{

	subcom25[j-k-1 ] = command2[j];
	i++;

	}

}	

	if(i<79&& command2[i] != 0)

	{
	k=i;
	for(int j = i +1 ; command2[j]!= ' ' && command2[j] != 0; j++)
		{

	subcom26[j-k-1 ] = command2[j];
	i++;

		}

	}	
}


//****************************************************************************************
// FUNCTION: clear()
// RETURNS:  void
// ARGUMENTS: void
// NOTES:  Use this to clear out our input and argument arrays
//****************************************************************************************

void clear()
{
	//loop through all 80 positions
	for(int i = 0; i < 80; i++)
		{
			
			
		//for each input and argument array, set element at position i to null terminator
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
	
}


//****************************************************************************************
// FUNCTION: erase()
// RETURNS:  void
// ARGUMENTS: char *v
// NOTES:  Use this to clear our double arrays, one row at a time.  Logically identical to clear()
//****************************************************************************************

void erase(char *v)
{

for(unsigned i = 0; i < sizeof(v); i++)
		v[i] = 0;
	
}


//****************************************************************************************
// FUNCTION: fill_argvs()
// RETURNS:  int
// ARGUMENTS: char **v
// NOTES:  This function takes the double array that is filled with the command and arguments we 
// want to execute.  We return the resulting execlp/execvp process id after passing in appropriate parameters.
//****************************************************************************************

int execute(char **v)
{

//if we have a command with no arguments, simply pass in the name of the command twice (once for $PATH, the other execution), and NULL.  return process id of call
	if(strcmp(v[1], empty)== 0)
		
		return execlp(v[0], v[0], NULL);
		
//if we have a command with one argument, do above except pass in the argument as well to execlp
		
	else if(strcmp(v[2], empty) == 0)
		
		return execlp(v[0], v[0], v[1], NULL);
			
//if we have a command with two arguments, do above except pass in the second argument as well to execlp
			
	else if(strcmp(v[3], empty) == 0)
		
		return execlp(v[0], v[0], v[1], v[2], NULL);
		
//if we have a command with three arguments, do above except pass in the third argument as well to execlp
			
	else if(strcmp(v[4], empty) == 0)
		
		return execlp(v[0], v[0], v[1], v[2], v[3], NULL);
		
//if we have a command with four arguments, do above except pass in the fourth argument as well to execlp
			
	else if(strcmp(v[5], empty) == 0)
		
		return execlp(v[0], v[0], v[1], v[2], v[3], v[4], NULL);
		
//otherwise, we have five arguments.  So pass in name of command, and the null-pointer-terminated double array argv1/2
			
	else
		return execvp(v[0], v);

}
