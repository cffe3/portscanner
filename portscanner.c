#include <stdio.h>
#include <stdlib.h> //for exit()
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error()
{
	
	perror( "[!]A error occurred \n" );
	printf( "[*]Exiting \n" );
	exit(1);
	
}

int syn_scan()
{
	struct sockaddr_in s_sock;
	
	int serv_sock;
	int port, beginning_port, ending_port;
	char ip_address[100];
	
	if((serv_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		
			error();
	
	return 1;		
	}
	
	s_sock.sin_family = AF_INET;
	
	printf( "[*]What is the IP address: " );
	scanf( "%s", &ip_address );
	
	s_sock.sin_addr.s_addr = inet_addr( ip_address );

	printf( "[*]Beginning port: " );
	scanf( "%i", &beginning_port );
	
	printf( "[*]Ending port: ");
	scanf( "%i", &ending_port );
	
	printf( "[*]Printing the results of the scan \n" );
	
	//start the for loop
	//in order to scan the 
	//IP given.
	for( port = beginning_port; port <= ending_port; port++ )
	{
		
		s_sock.sin_port = htons( port );
		
		//print the results
		//once done with basic testing
		//can make prettier.
		
		
		if(connect(serv_sock, (struct sockaddr *)&s_sock, sizeof(s_sock)) < 0)
		{
			
			printf( "%i    closed \n", port );
			
		}
		else
		{
			
			printf( "%i    open \n", port );
		
		}
		
	close( serv_sock );
	}
		
//once successful
//clean up
//by closing the socket and return 0
//return 0 tells the OS that the program exited without errors

printf( "[*]Done scanning \n" );
printf( "[*]Cleaning up \n" );

return 0;
}

int main( int argc, char *argv[] )
{
	
	int input;
	
	printf( "[0] Exit \n" );
	printf( "[1] Syn Scan \n" );
	printf( "[*]Scan type: " );	
	scanf( "%i", &input );
	
	//cannot equal 0
	//since 0 is exit
	if( input == 1 )
	{
			
		syn_scan();
			
	}
	//if equals 0, 
	//throw a error and exit
	else if( input == 0 )
	{
			
		error();
	
	return 1;
	}
	
return 0; //tells the OS that the program exited without errors
}
