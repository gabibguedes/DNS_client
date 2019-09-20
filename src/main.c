#include "dns_client.h"
#include "message.h"
#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>



int main(){
    unsigned char server_ip[16], url[100];
    unsigned char * request = (unsigned char *) malloc(sizeof(unsigned char) * BUFFER_SIZE);
    int size;
    
    scanf("%s", url);
    //scanf("%s", server_ip);

    size = create_msg(url, request);
    
    //search_ip(request, server_ip);
    for(int i = 0; i < size; i++){
        printf("%x %x\n", request[i], request[i+1]);
        i++;
    }
    free(request);
//    search_ip(url, server_ip); 
    return 0;
}
