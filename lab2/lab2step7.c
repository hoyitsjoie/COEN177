/*
# Name: Joy Zou 
# Date: TH 9:15 | 10/1/2020
# Title: Lab2 – Step 7
# Description: This program calls fork() and has the parent process wait until the child process is complete
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
    else if(pid == 0){
	execlp("/bin/ls", "ls", NULL);
    }
    else{
	// execlp("/bin/ls", "ls", NULL);
   	wait(NULL);
	printf("Child Complete \n");
	exit(0);
    }
    return 0;
}
