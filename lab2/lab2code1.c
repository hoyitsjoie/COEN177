/*
# Name: Joy Zou 
# Date: TH 9:15 | 10/1/2020
# Title: Lab2 – Step 1
# Description:This program calls fork() to create a child and parent process.User input will affect the duration of microsleep inside the for loop. 
*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
/* main function with command-line arguments to pass */
int main(int argc, char *argv[]) {
   
    pid_t  pid;
    int i;
    int n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    printf("\n Forked. \n");
   
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }

    if (pid == 0){
        for (i=0;i<100;i++) {
            printf("Child Process %d \n",i);
            usleep(n);
        }
    }
    else{
        for (i=0;i<100;i++) {
            printf("Parent Process %d\n",i);
            usleep(n);
        }
    }
    return 0;
}
