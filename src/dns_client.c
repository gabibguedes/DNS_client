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
          read_response(buffer);
          break;
    }
  } 
  
  close(socket_client);
  return buffer;
}

char* read_response(char * response){
    unsigned char * buff;
    msg_header * header = (msg_header *) response;

    // Jumps to the answer
    buff = (unsigned char *) &response[sizeof(msg_header)];
    //printf("mensagem td: %s\n", buff);

    // Jumps DNS
    while(buff[0] != '0') *buff++;
    *buff++;

    buff = &buff[20];
    // printf("com ntohs\n");
    // printf("--> %d\n", ntohs(buff[0]));
    // *buff++;
    // printf("--> %d\n", ntohs(buff[0]));
    // *buff++;
    // printf("--> %d\n", ntohs(buff[0]));
    // *buff++;
    // printf("--> %d\n", ntohs(buff[0]));
    // *buff++;
    printf("sem ntohs\n");
    printf("--> %d\n", buff[0]);
    *buff++;
    printf("--> %d\n", buff[0]);
    *buff++;
    printf("--> %d\n", buff[0]);
    *buff++;
    printf("--> %d\n", buff[0]);
    *buff++;

    //*buff +=2; // Jumps type size
    //*buff +=2; // Jumps class size
    //*buff +=2; // Jumps name class
    //*buff +=2; // Jumps answer type
    //*buff +=2; // Jumps type 
    //*buff +=2; // Jumps class
    //*buff +=4; // Jumps tll
    //*buff +=2; // Jumps data len
/*
    buff = &buff[18]; // data size
    printf("--> %u\n", buff[0]);
    *buff++;
    printf("--> %u\n", buff[0]);
    *buff++;
    printf("--> %u\n", buff[0]);
    *buff++;
    printf("--> %u\n", buff[0]);
    *buff++;
*/
// int j;
//     //for(j=0; buff[j] != '0'; j++);
//     //printf("j= %d\n", j);
//     buff = &buff[96]; // data size
//     //*buff++;
//     buff = &buff[10];
//     printf("--> %u\n", buff[0]);
//     *buff++;
//     printf("--> %u\n", buff[0]);
//     *buff++;
//     printf("--> %u\n", buff[0]);
//     *buff++;
//     printf("--> %u\n", buff[0]);
//     *buff++;
}
