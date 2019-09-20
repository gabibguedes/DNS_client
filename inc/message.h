#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include<stdio.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1024

char content[BUFFER_SIZE];

typedef struct _msg_header{
    u_int16_t transaction_id;
    u_int16_t flags;
    u_int16_t questoins_count;
    u_int16_t answers_count;
    u_int16_t authority_count;
    u_int16_t additional_count;
}msg_header;

typedef struct _question_info{
    u_int16_t type;
    u_int16_t klass;
}question_info;

void convert_hostname(unsigned char * hostname, unsigned char * response);
int create_msg(unsigned char* hostname, unsigned char* request);
#endif
