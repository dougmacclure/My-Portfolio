#
# PROGRAM:    assign6 makefile
# PROGRAMMER: Doug MacClure
# LOGON ID:   z0125061
# DATE DUE:   11/20/12
#

# Compiler variables
CCFLAGS = -Wall

# Rule to link object code files to create executable file
assign7: assign7.o 
	g++ $(CCFLAGS) -ggdb -o assign7 assign7.o 

# Rules to compile source code files to object code
assign7.o: assign7.cpp Queue.h 
	g++ $(CCFLAGS) -ggdb -c assign7.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign7

