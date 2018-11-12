#
# PROGRAM:    assign6 makefile
# PROGRAMMER: Doug MacClure
# LOGON ID:   z0125061
# DATE DUE:   11/01/12
#

# Compiler variables
CCFLAGS = -Wall

# Rule to link object code files to create executable file
assign6: assign6.o Stack.o
	g++ $(CCFLAGS) -ggdb -o assign6 assign6.o Stack.o

# Rules to compile source code files to object code
assign6.o: assign6.cpp Stack.h 
	g++ $(CCFLAGS) -ggdb -c assign6.cpp

Stack.o: Stack.cpp Stack.h
	g++ $(CCFLAGS) -ggdb -c Stack.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6

