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
