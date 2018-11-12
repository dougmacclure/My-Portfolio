/*
 * basicClient.cxx
 * 
 * TCP client
 * 
 * 	sends message to TCP server
 * 	waits for message received from server 
 * 	      
 * 	command line arguments:
 * 		argv[1] FQDN of server
 * 		argv[2] port number to send to
 * 		argv[3] request to send
 *  
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	if (argc != 4) {
		cerr << "USAGE: basicClient server_name port request\n";
		exit(EXIT_FAILURE);
	}
	
	// lookup FQDN
	struct addrinfo *res;	
	int error = getaddrinfo(argv[1], NULL, NULL, &res);
	if (error) {
		cerr << argv[1] << ": " << gai_strerror(error) << endl;
		exit(EXIT_FAILURE);
	}	
	
	char buffer[257];
	int echolen, received = 0;
	
	struct sockaddr_in echoserver;  // structure for address of server
	
	// Create the TCP socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("Failed to create socket");
		exit(EXIT_FAILURE);
	}
	
	// convert generic sockaddr to Internet sockaddr_in
	struct sockaddr_in *addr = (struct sockaddr_in *) res->ai_addr;
	
	// Construct the server sockaddr_in structure
	memset(&echoserver, 0, sizeof(echoserver));       /* Clear struct */
	echoserver.sin_family = AF_INET;                   /* Internet/IP */
	echoserver.sin_addr = addr->sin_addr;              /* IP address */
	echoserver.sin_port = htons(atoi(argv[2]));        /* server port */
	
	// connect to server
	if (connect(sock, (struct sockaddr *) &echoserver, sizeof(echoserver)) < 0) {
		perror("cannot connect");
		exit(EXIT_FAILURE);
	}
	
	// Send the message to the server 
	echolen = strlen(argv[3]);
	if (write(sock, argv[3], strlen(argv[3])) != echolen) {
		perror("Mismatch in number of sent bytes");
		exit(EXIT_FAILURE);
	}
	
	// Receive the message back from the server 
	do {
		received = read(sock, buffer, 256);
		if (received < 0) {
			perror("read failed");
			exit(EXIT_FAILURE);
		}
		buffer[received] = '\0'; // ensure string termination
		cout << buffer;
	} while (received > 0);
	cout << endl;
		
	close(sock);
	return 0;
}
           
