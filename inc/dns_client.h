#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include "message.h"


#define PORT 53


struct sockaddr_in si_other;
int socket_client;
int i; 
char buffer[BUFFER_SIZE];
//    Message message = Message();

struct _r_data{
    unsigned short type;
    unsigned short klass;
    unsigned int tll;
    unsigned short data_len;
}r_data;
        
char* search_ip(unsigned char* dns_server_ip, unsigned char* url_request, int size );
char* read_response(char * response, int size);
