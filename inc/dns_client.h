#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include "message.h"


#define PORT 5000


struct sockaddr_in si_other;
int socket_client;
int i; 
char buffer[BUFFER_SIZE];
//    Message message = Message();
        
char* search_ip(char* url, char* dns_server_ip);
