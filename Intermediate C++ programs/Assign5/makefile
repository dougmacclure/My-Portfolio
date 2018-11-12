#
# PROGRAM:    assign5
# PROGRAMMER: Doug MacClure
# LOGON ID:   z0125061
# DATE DUE:   10/25/12
#

# Compiler variables
CCFLAGS = -Wall

# Rule to link object code files to create executable file
assign5: assign5.o MyString.o
	g++ $(CCFLAGS) -ggdb -o assign5 assign5.o MyString.o

# Rules to compile source code files to object code
assign5.o: assign5.cpp MyString.h 
	g++ $(CCFLAGS) -ggdb -c assign5.cpp

MyString.o: MyString.cpp MyString.h
	g++ $(CCFLAGS) -ggdb -c MyString.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign5

