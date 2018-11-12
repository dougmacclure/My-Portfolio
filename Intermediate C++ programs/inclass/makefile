#
# PROGRAM:    assign2
# PROGRAMMER: Doug MacClure
# LOGON ID:   z0125061
# DATE DUE:   9/20/2012
#

# Compiler variables
CCFLAGS =i -Wall

# Rule to link object code files to create executable file
main: main.o SpecialArray.o
	g++ $(CCFLAGS) -o main main.o SpecialArray.o

# Rules to compile source code files to object code
main.o: main.cpp 
	g++ $(CCFLAGS) -c main.cpp

SpecialArray.o: SpecialArray.cpp SpecialArray.h
	g++ $(CCFLAGS) -c SpecialArray.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o SpecialArray

