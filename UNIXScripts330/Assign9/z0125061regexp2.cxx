//********************************************************************
// Doug MacClure
// CSCI330-3 
// Assignment 9
// This program is designed to emulate the Unix command "tee" to a certain
// degree of functionality.  It takes input from standard input (file descriptor 0)
// and copies it into multiple files.  -a allows us to append the files.
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
//char *line = NULL;

char wrt[5000] = {0};
char line[5000] = {0};
char buffer[100000];
char single;
int count = 1;
int k;
int j;
int l = 0;
//size_t k = 0;
char option[] = "-a";
char rexpop[] = "-f";
regex_t regex;
int rs;


cerr << "Num args: " << argc;

//if the only command line argument is the name of the program, send error message and exit
if(argc < 2)
	
		{
		
		cerr << "Not enough command line arguments.  Format: z0125061.tee [-a] outFile1 [outfile2] ...";
		exit(EXIT_FAILURE);
		
		}


//case 1: we do not want to append our output

if(strcmp(argv[1], option) != 0)

	{
		
	j = 0;
	//for(unsigned i = 0; i < sizeof(option); i++)
		
	for(int i = 1 + j; i < argc; i++)
	
		{
			cerr << argv[i];
		
			if(strcmp(argv[i],rexpop) == 0)
				
				i+=2;
		
			cerr << argv[i];
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

	for(int i = 1 + j; i < argc; i++)
	
		{
						
			if(strcmp(argv[i],rexpop) == 0)
				{
			
				i++;
				i++;
				
				}
				
			filed[i-1] = open(argv[i], O_WRONLY | O_APPEND | O_CREAT, 00666);
			
			//if we got a bad file descriptor, then we were unable to open file.  Indicate error and exit.
			if (filed[i-1] == -1)
		
				{
				
				cerr << argv[i] << " can't be opened.\n";
							
				}
			
						
		}
	
	}

	//read file

    count = read(0, buffer, 100000);
	while (count != 0)
		{
		l = 0;	
		k = 0;
		while ( k < count)
		
			{
				
			single = buffer[k];	
			k++;
			
			if( single == '\n')
			
				{
				
				//line[l] = single;
		
				for(int i = 1 + j; i < argc; i++)
					{
		
					
		
					if(strcmp(rexpop, argv[i]) == 0)
		
						{
										
						i++;
						
						rs = regcomp(&regex, argv[i], 0);
								
						if (rs == 0)
				
							{
							//cerr << argv[i];
							//execute reg expression
							rs = regexec(&regex, line, 0, 0, 0);
							cerr << "result for " << argv[i] << ": " << rs;			
							if( rs == 0 )
					
								{
							
									//cerr << line << " is matched by: " << argv[i];
									i++;	
									cerr << "writing to " << argv[i];
									strcpy(wrt, line);
									wrt[l] = single;
									write(filed[i-1], wrt, l + 1);
									for (unsigned m= 0; m < 5000; m++)
										wrt[m] = 0;
										
								
								}
								
							else
							
								{
								//cerr << line << " is not matched by: " << argv[i];
							
								
								i++;
								}
							
						
							}
							
						
						else
							
							{
							cerr << argv[i-1] << " was a bad regular expression.";
							i++;
							strcpy(wrt, line);
							wrt[l] = single;
							write(filed[i-1], wrt, l + 1);
							for (unsigned m= 0; m < 5000; m++)
								wrt[m] = 0;
										
									
															
							}
					
						}
					
				else
				
					{
					
						if(filed[i-1] > 0)
					
							{
							cerr << "writing to " << argv[i] << " w/o regexp";
							strcpy(wrt, line);
							wrt[l] = single;
							write(filed[i-1], wrt, l + 1);
							for (unsigned m= 0; m < 5000; m++)
								wrt[m] = 0;
										
							}				
					}
				
				}
				
					strcpy(wrt, line);
					wrt[l] = single;
					write(1, wrt, l + 1);
					for (unsigned m= 0; m < 5000; m++)
						wrt[m] = 0;
					l = 0;
					for (unsigned m= 0; m < 5000; m++)
						line[m] = 0;
				
			}


	else
	{
		
		line[l] = single;
		l++;
			
	}


		
		
		}
	count = read(0, buffer, 1024);

	}


}


