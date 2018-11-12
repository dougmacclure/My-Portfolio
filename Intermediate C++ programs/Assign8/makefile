#
# PROGRAM:    assign6 makefile
# PROGRAMMER: Doug MacClure
# LOGON ID:   z0125061
# DATE DUE:   11/20/12
#

# Compiler variables
CCFLAGS = -Wall

# Rule to link object code files to create executable file
assign8: assign8.o 
	g++ $(CCFLAGS) -ggdb -o assign8 assign8.o 

# Rules to compile source code files to object code
assign8.o: assign8.cpp Deque.h 
	g++ $(CCFLAGS) -ggdb -c assign8.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8

