
//NOTE:  THIS PROGRAM WILL WORK IN TURING/HOPPER

//Doug MacClure
//CSCI330-3
//Assignment 10
//UDP Program: Access credit card server, send it a credit card transaction and receive message from server.


#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

//helper function prototypes
void erase(char *);
bool checkcc(char *);
bool checkexp(char *);
bool checkamt(char *);


int main() {
	

	//this array is used when receiving data from server
	char buffer[256];

	//stores port #
	char port[] = "9045";
	
	//stores server's fully qualified domain name
	char fqdn[] = "hopper.cs.niu.edu";

	//this array holds all data that we send to server
	char info[128] = {0};
	
	//holds dollar amount
	char amount[16];
	//holds expiration date
	char expiry[8];
	//holds credit card #
	char ccnum[20];
	//used for option to quit
	char ext[] = "quit";
	//holds card holder name, and used to check if user wants to quit
	char name[64] = {0};
	//is the # of chars we are sending to server
	int infolength = 0;
	//holds the size of the server's address
	unsigned int addrlen;
	//holds return status of socket function which creates a socket
	int sock;
	struct sockaddr_in ccserver;  // structure for address of server
	
	struct addrinfo *res;	
	//get server address information by calling getaddrinfo so we can use bind function
	int error = getaddrinfo(fqdn, NULL, NULL, &res);
	//if we were unable to prepare to get address structures required for bind to server associated with fqdn, then it will 
	//return 1, then print error message and exit
	if (error) {
		cerr << fqdn << ": " << gai_strerror(error) << endl;
		exit(EXIT_FAILURE);
	}	
	
	
	//prompt user for data
	cerr << "Welcome to the Credit Card transaction verification utility" << endl;
	cerr << "Enter card holder name (or quit): ";
	cin.getline(name, 64);
		//if user entered "quit" exit program
		if(strcmp(name, ext)==0)

			exit(0);
	
	//prompt for credit card #, place in holding space
	cerr << "Enter CC number: ";
	cin.getline(ccnum, 20);
	//call checkcc helper function which checks if what user entered was a well-formed 15-16 digit number representing a credit card number
	//if user entered bad info, ask for input again until user enters valid cc#
	while(!checkcc(ccnum))
		
		{
		erase(ccnum);	
		cerr << "... credit card number invalid, try again: ";
		cin.getline(ccnum, 20);	
					
		}
	
	//prompt user for expiration date
	cerr << "Enter expiration: ";
	cin.getline(expiry, 8);
	
	//call checkexp helper function that checks to make sure user entered well-formed expiration date.  if not, keep asking user for valid
	//expiry date until user enters correct info
	while(!checkexp(expiry))
	
		{
			
		erase(expiry);
		cerr << "... expiration date invalid, try again: ";
		cin.getline(expiry, 8);	
			
		}
	
	//prompt for dollar amount
	cerr << "Enter amount: ";
	cin.getline(amount, 16);
	//call checkamt helper function to make sure user entered well-formed dollar amount data.  if user didn't enter correctly, keep calling function
	while(!checkamt(amount))
	
		{
		erase(amount);
		cerr << "... amount invalid, try again: ";	
		cin.getline(amount, 16);
			
		}
	
	//build our info array which holds the data we send to ccserver according to desired specifications
	strcat(info, ccnum); strcat(info, ":");
	strcat(info, expiry); strcat(info, ":");
	strcat(info, amount);
		
		
	// Create the UDP socket
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
	{
	
		perror("Failed to create socket");
		exit(EXIT_FAILURE);
	
	}
	
	// convert generic sockaddr to Internet sockaddr_in
	struct sockaddr_in *addr = (struct sockaddr_in *) res->ai_addr;
	
	// Construct the server sockaddr_in structure
	memset(&ccserver, 0, sizeof(ccserver));       /* Clear struct */
	ccserver.sin_family = AF_INET;                   /* Internet/IP */
	ccserver.sin_addr = addr->sin_addr;   /* IP address */
	ccserver.sin_port = htons(atoi(port));        /* server port */
	
	// Send the message to the server 
	infolength = strlen(info);
	if (sendto(sock, info, strlen(info), 0, (struct sockaddr *) &ccserver, sizeof(ccserver)) != infolength) 
	{
	
		perror("Mismatch in number of sent bytes");
		exit(EXIT_FAILURE);
	
	}
	
	// Receive the message back from the server 
	addrlen = sizeof(ccserver);
	recvfrom(sock, buffer, 256, 0, (struct sockaddr *) &ccserver, &addrlen);
	
	//print message received from server	
	cout << endl << buffer<< endl;
	
	//close socket
	close(sock);
	return 0;
}
           

//****************************************************************************************
// FUNCTION: checkcc()
// RETURNS:  bool
// ARGUMENTS: char *v
// NOTES: Checks to make sure that user entered in either digits or spaces.  There are many
//  ways to enter a 15-16 digit with ambigious # of spaces, so that is outside of the scope of what we can do
//****************************************************************************************

bool checkcc(char *v)
{
//loop through passed in array
for(unsigned i = 0; i < sizeof(v); i++)

	//if the element of array at position i is neither a space nor a digit, return false and exit helper function
	if(!isdigit(v[i]) && !isspace(v[i]))
	
		return false;

//if we have gone through array without exiting function, return true
return true;
}

//****************************************************************************************
// FUNCTION: erase()
// RETURNS:  void
// ARGUMENTS: char *v
// NOTES:  This function simply sets passed in array to an array of null terminators
// 
//****************************************************************************************

void erase(char *v)
{

for(unsigned i = 0; i < sizeof(v); i++)
		v[i] = 0;
	
}

//****************************************************************************************
// FUNCTION: checkexp()
// RETURNS:  bool
// ARGUMENTS:  char *v
// NOTES:  This helper function checks every position of passed in array, to make sure that 
// user entered date in correct format that server is expecting.
//****************************************************************************************

bool checkexp(char *v)
{

//if passed in array does not hold string of format: ##/#### with 3rd # = 2, 4th # = 0, and 5th # != 0, then return false
if(!isdigit(v[0]) || !isdigit(v[1]) || v[2] != '/' || !isdigit(v[3]) || !isdigit(v[4]) || !isdigit(v[5]) || !isdigit(v[6]) 
   || v[3] != '2' || v[4] != '0' || v[5] == '0') 
	
	return false;

//otherwise array passes test
else

	return true;
}

//****************************************************************************************
// FUNCTION: checkamt()
// RETURNS:  bool
// ARGUMENTS:  char *v
// NOTES:  This helper function checks if last two elements in array before null terminator  
// are digits, and the element before the two digits is '.' and whether all other elements 
// are digits. 
//****************************************************************************************

bool checkamt(char *v)
{

//temporary placeholder that is meant to "point" to the null terminator
unsigned u = 0;

//loop through array until null terminator
for(unsigned i = 0; v[i] != 0; i++)

		u = i;

//makes sure u is the subscript of the first null terminator in array
u++;
	

//loop through array until the expected '.', which is supposed to be 3 elements to the "left" of the first null terminator
//which is held at subscript "u", or until we find an element that is not a digit before the '.'
for(unsigned i = 0; i < (u-3); i++) 

	if(!isdigit(v[i]))
	
		//if we encounter something other than a digit before '.' return false
		return false;

//second test is to make sure the '.' is where it is supposed to be, if not return false
if(v[u-3] != '.')

	return false;
	
//if the last two elements before null terminator are not digits return false
if(!isdigit(v[u-2]) || !isdigit(v[u-1]))

	return false;
	
//otherwise the array passes the test, return true
else

	return true;
}
