#include "message.h"

void convert_hostname(unsigned char * hostname, unsigned char *response){
   int lock = 0, i;
   
   // Adds a dot at the end 
   strcat((char *) hostname, ".");

   for(i = 0; i<strlen((char*)hostname); i++){
        if(hostname[i] == '.'){

            // The number of characters until the dot.
            int a = i - lock;
            *response= i - lock;
            // Goes to the next position
            *response++;

            for(;lock < i;lock++){
                //Copy the hostname to the response
                *response = hostname[lock];
                //Goes to the next position
                *response++;
            }

            lock = i + 1;
        }
   }
   *response = '\0';
}

int create_msg(unsigned char* hostname, unsigned char* request){
    unsigned char * body;
    msg_header * header;
    question_info * info;

    // The random number for the id is 123
    int id = 123;

    header = (msg_header *) request;

    // Add the header configuration
    header->transaction_id = id; // Add the random id to the message
    header->flags = htons(256); // Activates recusive search flag
    header->questoins_count = htons(1); // The number of questions
    header->answers_count = 0;
    header->authority_count = 0; 
    header->additional_count = 0;

    // Add the hostname to the message structure
    body = &request[sizeof(msg_header)]; // Jump the header position, and goes to the body position
    convert_hostname(hostname, body);

    // Add the question info to the message
    info = (question_info*)&request[sizeof(msg_header) + strlen((char * )body) + 1]; // Jump the body and header position, and goes to the info position
   info->type = htons(1);
    info->klass = htons(1);

    // Returns the size of the message
    return (sizeof(msg_header) + strlen((char *) body) + sizeof(question_info)) + 1;
}
