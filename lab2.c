// Short Notes
// the tasks of input function is handled by the fgets function!
// cmd is the arrray of strings
// Array is a finite set of homegeneous elements!
// char variable takes 1 byte of memory
// pointer variable takes 8 bytes of memory
// token is created, on basis on space, \n -(enter), tab 

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
// strtok - we have to pass cmd, strtok- returns first address of token! (its scans the string , where ever it finds,[space, \n -(enter), tab] it creates the token, and first address of that token is returned!)
// strtok(NULL, " \n\t") - it continues from the last position where it left off!

// #include <stdio.h>
// int main (){
//     int x = 15;   // declared an integer variable
//     int *p;       // declared a pointer variable
//     p = &x;       // assigned the address of x to pointer p
//     printf("Value of x = %d\n", x);          // prints the value of x
//     printf("Address of x = %p\n", &x);       // prints the address of x
//     printf("Value of p = %p\n", &p);          // prints the address of pointer p
//     printf("Address stored in p = %p\n", p); // prints the address stored in pointer p 
//     printf("Value pointed to by p = %d\n", *p); // re-differencing pointer p to get the value of x
//     *p = 17;
//     printf("x val = %d\n", x);
//     printf( "x val via p val = %d\n", *p);
//     return 0; //signals that program ended successfully
// }


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LEN 1024
#define MAX_ARGS 64

void parse(char *cmd, char **args){
    int i = 0;
    args[i] = strtok(cmd, " \t\n");
    while (args[i] && i < MAX_ARGS -1)
        args[++i] = strtok(NULL, " \t\n");
    args[i] = NULL;
}



// exicute the command using fork + exec

void execute(char **args){
    pid_t pid = fork();

    if (pid ==0){
        execvp(args[0], args);
        perror("command not found");
        _exit(1);
    } else{
        wait(NULL);
        //parent waits 
    }
}

int main() {
    char cmd[MAX_LEN];
    char *args[MAX_ARGS];
    while (1){
        printf("myshell> ");
        if (!fgets(cmd, MAX_LEN, stdin))
            break; // exit on Ctrl+D
        if (cmd[0]=='\n')
            continue; // ignore empty input 
        parse(cmd, args);
        if (strcmp(args[0], "exit")==0)
            break; // exit on 'exit' command
        execute(args);
        }
    return 0;
}
