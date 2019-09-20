#include "dns_client.h"
#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>


char* search_ip(char* url_request, char* dns_server_ip){
  
  int si_other_size = sizeof(si_other);
  if((socket_client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
    perror("Error while opening UPD socket\n");
    exit(-1);
  }

  memset((char *) &si_other, 0, sizeof(si_other));
  si_other.sin_family = AF_INET;
  si_other.sin_port = htons(PORT);
  
  if(inet_aton(dns_server_ip, &si_other.sin_addr) == 0){
    perror("inet error\n");
    exit(-1);
  }

  //message.create_message(url_request);
  char *message = url_request;

  for(int i =0; i < 3; i++){
    //if(sendto(socket_client, this.message.content, 
    if(sendto(socket_client, message, 
        strlen(message), 0, (struct sockaddr *) &si_other,
        si_other_size) == -1 ){
          perror("Error while trying to send a message\n");
          exit(-1);
    }

    memset(buffer, '\0', BUFFER_SIZE); 
    if(recvfrom(socket_client, buffer, BUFFER_SIZE, 0, 
        (struct sockaddr *) &si_other, &si_other_size) != -1){
          printf("%s\n", buffer);
          break;
    }
  } 
  
  close(socket_client);
  return NULL;
}
