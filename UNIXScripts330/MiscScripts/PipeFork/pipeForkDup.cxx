/*
 * pipeForkDup.cxx
 * 
 * 	Example Program for CSCI 330
 *  shows pipe, fork, dup and execl system calls
 * 
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	
	int pipefd[2], rs;
	
	// create pipe
	rs = pipe(pipefd);
	if (rs == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	cerr << "pipe created\n";
	
	// fork into 2 processes
	rs = fork();
	if (rs == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	
	if (rs == 0) { // child process	
		// close write end of pipe, keep read end open
		close(pipefd[1]);
		// close standard input
		close(0);
		// duplicate read end of pipe into standard input
		dup(pipefd[0]);
		// close read end of pipe
		close(pipefd[0]);
		
		// run wc
		rs = execl("/usr/bin/wc", "wc", (char*)NULL);
		if (rs == -1) {
			perror("execl");
			exit(EXIT_FAILURE);
		}
			
	} else {  // parent process	
		// close read end of pipe, keep write end open
		close(pipefd[0]);
		// close standard output so that the output of command goes 
		//"into" the current program
		close(1);
		// duplicate write end of pipe into standard output
		dup(pipefd[1]);
		// close write end of pipe
		close(pipefd[1]);
		
		// run ls
		rs = execl("/bin/ls", "ls", (char*)NULL);
		if (rs == -1) {
			perror("execl");
			exit(EXIT_FAILURE);
		}
		// uselesscextra call
		wait(&rs);	
	}	
	return 0;
}
