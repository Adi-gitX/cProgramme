// Short Notes
// the tasks of input function is handled by the fgets function!
// cmd is the arrray of strings
// Array is a finite set of homegeneous elements!
// char variable takes 1 byte of memory
// pointer variable takes 8 bytes of memory
// 

//Task 1: reading the commmand --understand deeply, nature of \0
//Task 2: after reading the string create the token of the string, and then traverse on the string! -- track of tokens
//Task 3: 

// #include <stdio.h>
// #include <string.h>

// int main(){
//     char msg[20];
//     char msg[] = "Hello, World!";
//     printf("string length = %lu\n", strlen(msg));  // lu means unsigned long, strlen means string length and it returns size_t type
//     for (int i=0; msg[i]!='\0';i++){
//         printf( "%c\n", msg[i])
//     }
//     return 0;
// }

// pointer - which stores the address of another variable
#include <stdio.h>
int main (){
    int x = 15;   // declared an integer variable
    int *p;       // declared a pointer variable
    p = &x;       // assigned the address of x to pointer p
    printf("Value of x = %d\n", x);          // prints the value of x
    printf("Address of x = %p\n", &x);       // prints the address of x
    printf("Value of p = %p\n", &p);          // prints the address of pointer p
    printf("Address stored in p = %p\n", p); // prints the address stored in pointer p 
    printf("Value pointed to by p = %d\n", *p); // prints the value pointed to by pointer p
    *p = 17;
    printf("x val = %d\n", x);
    printf( "x val via p val = %d\n", *p);
    return 0;
}