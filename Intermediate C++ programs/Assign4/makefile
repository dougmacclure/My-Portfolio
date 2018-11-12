#
# PROGRAM:    assign2
# PROGRAMMER: Doug MacClure
# LOGON ID:   z0125061
# DATE DUE:   9/20/2012
#

# Compiler variables
CCFLAGS = -Wall

# Rule to link object code files to create executable file
assign4: assign4.o MyString.o
	g++ $(CCFLAGS) -o assign4 assign4.o MyString.o

# Rules to compile source code files to object code
assign4.o: assign4.cpp MyString.h 
	g++ $(CCFLAGS) -c assign4.cpp

MyString.o: MyString.cpp MyString.h
	g++ $(CCFLAGS) -c MyString.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4

