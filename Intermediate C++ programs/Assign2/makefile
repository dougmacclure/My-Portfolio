#
# PROGRAM:    assign2
# PROGRAMMER: Doug MacClure
# LOGON ID:   z0125061
# DATE DUE:   9/20/2012
#

# Compiler variables
CCFLAGS = -ansi -Wall

# Rule to link object code files to create executable file
assign2: assign2.o Product.o Store.o
	g++ $(CCFLAGS) -o assign2 assign2.o Product.o Store.o

# Rules to compile source code files to object code
assign2.o: assign2.cpp Store.h
	g++ $(CCFLAGS) -c assign2.cpp

Product.o: Product.cpp Product.h
	g++ $(CCFLAGS) -c Product.cpp

Store.o: Store.cpp Store.h
	g++ $(CCFLAGS) -c Store.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2

