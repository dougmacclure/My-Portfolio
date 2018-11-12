#
# PROGRAM:    assign2
# PROGRAMMER: Doug MacClure
# LOGON ID:   z0125061
# DATE DUE:   9/20/2012
#

# Compiler variables
CCFLAGS = -Wall

# Rule to link object code files to create executable file
assign3: assign3.o Verifier.o
	g++ $(CCFLAGS) -o assign3 assign3.o Verifier.o

# Rules to compile source code files to object code
assign3.o: assign3.cpp Verifier.h
	g++ $(CCFLAGS) -c assign3.cpp

Verifier.o: Verifier.cpp Verifier.h
	g++ $(CCFLAGS) -c Verifier.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign3

