
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

int clientSocket, portNum;
char buffer[1024];
struct sockaddr_in serverAddr;
socklen_t addr_size;
pthread_t tid;


void create_client_socket(char *ip, int port) {
  /*Create UDP socket*/
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr.s_addr = inet_addr(ip);
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverAddr;


}

char *recv_data() {

   recvfrom(clientSocket,buffer,1024,0,NULL, NULL);
   return buffer;
}

void *send_data(char *buffer, int nBytes) {
   sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);
}

void inisialisasi(char *buffer, int nBytes) {

	pthread_create(&tid,NULL,send_data(buffer, nBytes),NULL);
	pthread_join(tid,NULL);
}
