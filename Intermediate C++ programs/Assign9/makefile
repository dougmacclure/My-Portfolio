#
# PROGRAM:    assign9 makefile
# PROGRAMMER: Doug MacClure
# LOGON ID:   z0125061
# DATE DUE:   12/5/12
#

# Compiler variables
CCFLAGS = -Wall

# Rule to link object code files to create executable file
assign9: assign9.o 
	g++ $(CCFLAGS) -ggdb -o assign9 assign9.o 

# Rules to compile source code files to object code
assign8.o: assign9.cpp quicksort.h 
	g++ $(CCFLAGS) -ggdb -c assign9.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign9

