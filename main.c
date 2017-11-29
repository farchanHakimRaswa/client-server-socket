
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"

int port = 7891;
int nBytes;
char *ip = "127.0.0.1";
char buffer[1024];
int main() {

        

        create_client_socket(ip, port);
	while(1) {
		printf("Type a sentence to send to server:\n");
    		fgets(buffer,1024,stdin);
    		printf("You typed: %s",buffer);
    		nBytes = strlen(buffer) + 1;
		inisialisasi(buffer,nBytes);
	}
}
