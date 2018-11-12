//
//EXTRA CREDIT ATTEMPT
//


//********************************************************************
// Doug MacClure
// CSCI330-3 
// Assignment 9
// This program is designed to emulate the Unix command "tee" to a certain
// degree of functionality.  It takes input from standard input (file descriptor 0)
// and copies it into multiple files.  -a allows us to append the files.  -f allows regular expression pattern matching
// NOTE: This program expects command line arguments.
// COMMAND LINE FORMAT: ./z0125061 [-a] [-f "regular expression"] outFile1 [[-f "reg exp"] outFile2] ...
//
//********************************************************************


#include <regex.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <istream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

//we are given input from a command that is piped into or typed into this program
//we want to take that stream of input, and copy it into a list
//of files indicated as command line arguments

int main(int argc, char* argv[])
{

//this array holds the file descriptors for all files that are to be created/opened 
int filed[argc - 1];

//we use this C-string to copy data from standard input into the various outFiles
char wrt[50000] = {0};

//we use this for testing regular expression matches
char line[50000] = {0};

//holding space from read system call
char buffer[1000000];

//we use this to iterate through buffer
char single;

//keeps track of how many bytes were read from standard input
int count = 1;

//index variables
int k;
int j;
int l = 0;

//used to compare command line arguments with valid implmented options
char option[] = "-a";
char rexpop[] = "-f";

//regex patternspace variable
regex_t regex;

//holds return statuss for regcomp and regexec functions
int rs;

//if the only command line argument is the name of the program, send error message and exit
if(argc < 2)
	
		{
		
		cerr << "Not enough command line arguments.  Format: z0125061.tee [-a] [-f 'reg exp'] outFile1 [[-f 'reg exp'] outfile2] ...";
		exit(EXIT_FAILURE);
		
		}


//case 1: we do not want to append our output

if(strcmp(argv[1], option) != 0)

	{
		
	j = 0;
	//for(unsigned i = 0; i < sizeof(option); i++)
		
	for(int i = 1 + j; i < argc; i++)
	
		{
			
			if(strcmp(argv[i],rexpop) == 0)
				
				i+=2;
	
			//open the file indicated in argv[i], and store the resulting file
			//descriptor from calling the open system call into the file descriptor array
			filed[i-1] = open(argv[i], O_WRONLY | O_CREAT, 00666);
			//if we got a bad return status from open system call, indicate file can't be opened
			//and move onto next file
			if (filed[i-1] == -1)
		
				{
				
				cerr << argv[i] << " can't be opened.\n";
							
				}


		}
		
	}

//case 2: we want to append output to files
else

	{

	//if the command line only consists of the name of the file and the -a option, indicate error and exit

	if(argc < 3)
	
		{
		
		cerr << "Not enough command line arguments.  Format: z0125061.tee [-a] outFile1 [outfile2] ...";
		exit(EXIT_FAILURE);
		
		}

	//we now need to move where the first filename comes from on the command line by one to the right

	j = 1;
	//loop through command line args
	for(int i = 1 + j; i < argc; i++)
	
		{
			//if we encounter a '-f', iterate twice to position where filneame corresponding to '-f' should be
			if(strcmp(argv[i],rexpop) == 0)
				{
			
				i++;
				i++;
				
				}
			// open file
			filed[i-1] = open(argv[i], O_WRONLY | O_APPEND | O_CREAT, 00666);
			
			//if we got a bad file descriptor, then we were unable to open file.  Indicate error and exit.
			if (filed[i-1] == -1)
		
				{
				
				cerr << argv[i] << " can't be opened.\n";
							
				}
			
						
		}
	
	}

	//read file

    count = read(0, buffer, 1000000);
	
	//while we have stuff to read
	while (count != 0)
		{
		//reset buffer iterator to zero
		
		k = 0;
		
		//while our buffer has new stuff in it we haven't read yet
		while ( k < count)
		
			{
				
			//take a character out of the buffer and iterate to next position
			single = buffer[k];	
			k++;
			
			//if this character is a newline character, then we want to begin writing line to files
			if( single == '\n')
			
				{
				
				for(int i = 1 + j; i < argc; i++)
					{
		
					//if we have encountered a '-f', we have to deal with regular expression filtering for this line
					
					if(strcmp(rexpop, argv[i]) == 0)
		
						{
										
						//so iterate to next position, which is the regular expression pattern
						i++;
						
						//call regcomp to build pattern space
						rs = regcomp(&regex, argv[i], 0);
								
						//if argv[i] is actually a regular expression
						if (rs == 0)
				
							{
							//execute reg expression
							rs = regexec(&regex, line, 0, 0, 0);
										
							//if our regular expression finds a match within the line, we want to write out to file
							if( rs == 0 )
					
								{
							
									//iterate to next position on commandline
									i++;	
									
									//since we do not want newline character at end of our line array (this will cause an error when matching reg expressions & end of words or
									//end of lines), and we skipped newline char from our buffer, then utilize our other array to copy over line plus a newline char at
									//the end
							
									for(unsigned n= 0; n< sizeof(line); n++)
										wrt[n] = line[n];
									wrt[l] = single;
									
									//write line to file
									write(filed[i-1], wrt, l + 1);
									
									//clear out our write array
									for (unsigned m= 0; m < 50000; m++)
										wrt[m] = 0;
										
								
								}
								
							else
							
								{
															
								//otherwise, our regular expression has not found a match.  so iterate to next command line argument
								i++;
								}
							
						
							}
							
						
						else
							
							{
								
							//the regular expression user wrote was invalid, so ignore it and write line anyway					
							i++;
							
							//same write method as above
							//strcpy(wrt, line);
							for(unsigned n= 0; n< sizeof(line); n++)
								wrt[n] = line[n];
							wrt[l] = single;
							write(filed[i-1], wrt, l + 1);
							for (unsigned m= 0; m < 50000; m++)
								wrt[m] = 0;
										
									
															
							}
					
						}
					
				//otherwise, user is not using regular expressions
					
				else
				
					{
						
						//prepare to write to file.  make sure filedescriptor is good
						if(filed[i-1] > 0)
					
							{
								
							//same write method as above
						
							for(unsigned n= 0; n< sizeof(line); n++)
								wrt[n] = line[n];
							wrt[l] = single;
							write(filed[i-1], wrt, l + 1);
							for (unsigned m= 0; m < 50000; m++)
								wrt[m] = 0;
										
							}				
					}
				
				}
				
				
				//we have finally looped through command line arguments, and can now write to standard output with same write method as above

					for(unsigned n= 0; n< sizeof(line); n++)
										wrt[n] = line[n];
				wrt[l] = single;
				write(1, wrt, l + 1);
				for (unsigned m= 0; m < 50000; m++)
					wrt[m] = 0;
				
				//reset line position to 0
				l = 0;
				//we also need to clear out our line array
				for (unsigned m= 0; m < 50000; m++)
					line[m] = 0;
				
			}


	
	//otherwise, within the buffer, we are not at the end of a line, so continue copying characters of current line to our line array
	else
	{
		
		line[l] = single;
		l++;
			
	}


		
		
		}
	//continue or end loop by reading from standard input again
	count = read(0, buffer, 1000000);
	
	}
	
	
//close all open files

for(int i = 1 + j; i < argc; i++)
	
		{
			
			if(strcmp(argv[i],rexpop) == 0)
				
				i+=2;
	
			//close the file indicated in argv[i]
			rs = close(filed[i-1]);
			//if we got a bad return status from close system call, indicate error
				if (rs == -1)
		
				{
				
				cerr << argv[i] << " can't be closed.\n";
							
				}


		}


}


