#include "dns_client.h"
#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

char* search_ip(unsigned char* dns_server_ip, unsigned char* url_request, int size){
  int si_other_size = sizeof(si_other);
  if((socket_client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1){
    perror("Error while opening UPD socket\n");
    exit(-1);
  }

  memset((char *) &si_other, 0, sizeof(si_other));
  si_other.sin_family = AF_INET;
  si_other.sin_port = htons(PORT);
  si_other.sin_addr.s_addr = inet_addr((char *)dns_server_ip);

  char *message = (char *) url_request;

  for(int i =0; i < 3; i++){
    if(sendto(socket_client, message, size, 0, (struct sockaddr *) &si_other,
        si_other_size) == -1 ){
          perror("Error while trying to send a message\n");
          exit(-1);
    }

    memset(buffer, '\0', BUFFER_SIZE); 
    if(recvfrom(socket_client, buffer, BUFFER_SIZE, 0, 
        (struct sockaddr *) &si_other, (socklen_t *)&si_other_size) != -1){
          //printf("%s\n", buffer);
          read_response(buffer,size);
          break;
    }
  } 
  
  close(socket_client);
  return buffer;
}

char* read_response(char * response, int size ){
    unsigned char * buff;
    msg_header * header = (msg_header *) response;

    buff = (unsigned char*) &response[size+12];
    printf("%u.", buff[0]);
    *buff++;
    printf("%u.", buff[0]);
    *buff++;
    printf("%u.", buff[0]);
    *buff++;
    printf("%u\n", buff[0]);
    *buff++;

    return buff;   
}
