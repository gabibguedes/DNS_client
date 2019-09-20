#include "dns_client.h"
#include "message.h"
#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>



int main(){
    unsigned char server_ip[160], url[100];
    scanf("%s", url);
    //scanf("%s", server_ip);

    char a[30];
    convert_hostname(url, server_ip );
    printf("%s\n", server_ip);
//    search_ip(url, server_ip); 
    return 0;
}
