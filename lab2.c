// Short Notes
// the tasks of input function is handled by the fgets function!

//Task 1: reading the commmand 
//Task 2: after reading teh string create the token of the string, and then traverse on the string!


#include <stdio.h>
#include <string.h>

int main(){
    char msg[20];
    char msg[] = "Hello, World!";
    printf("string length = %lu\n", strlen(msg));  // lu means unsigned long, strlen means string length and it returns size_t type
    for (int i=0; msg[i]!='\0';i++){
        printf( "%c\n", msg[i])
    }
}

