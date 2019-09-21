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
    char * response;

    printf("URL: ");
    scanf("%s", url);
    printf("DNS server: ");
    scanf("%s", server_ip);

    printf("searching %s on %s...\n", url, server_ip);

    size = create_msg(url, request);
    printf("Mensagem: \n");
    for(int i = 0; i < size; i++){
        printf("%d %d\n", request[i], request[i+1]);
        i++;
    }
    
    response = search_ip(server_ip, request, size);
    printf("Resposta: \n");
    for(int i = 0; i < size; i++){
        printf("%u %u\n", response[i], response[i+1]);
        i++;
    }
    free(request);
//    search_ip(url, server_ip); 
    return 0;
}
