/*
# Name: Joy Zou 
# Date: TH 9:15 | 10/1/2020
# Title: Lab2 – Step 5
# Description: This program calls fork() multiple times so that each parent process has 2 or 0 child processes
*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
/* main function with command-line arguments to pass */
int main() {
   
    pid_t  pid, pid2, pid3, pid4, pid5, pid6;
    int i;
   // int n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before forking.\n");
    pid = fork();
    printf("\n ////////////Forked.//////// \n");
    printf("pid: %d parentid: %d\n",getpid(),getppid()); 
    printf(" \n"); 
    if (pid == -1) {
        fprintf(stderr, "can't fork, error %d\n", errno);
    }
    if (pid == 0){
            printf("Process %d w/ parentId %d\n",getpid(),getppid());
    }
    else{
            printf("Process %d w/parentId %d\n",getpid(),getppid());
 	    
            pid2 = fork();

	    if(pid2 == 0){
		printf("PPPPProcess %d w/parentId %d\n",getpid(),getppid());
		pid3= fork();
		if(pid3==0){
			printf("Process %d w/parentId %d\n",getpid(),getppid());
		}else{
	       		pid4=fork();
                	if(pid4==0){
               			 printf("Process %d w/parentId %d\n",getpid(),getppid());

                       	 	pid5 =fork();
                       	 	if(pid5==0){
                                	printf("Process %d w/parentId %d\n",getpid(),getppid()); 
                       	 	}
				else{
					pid6 = fork();
                                	if(pid6==0){
                                        	printf("Process %d w/parentId %d\n",getpid(),getppid());
                               	 	}     
				}
               		}	
	        }
	    }
	    else{
		printf("ppppprocess %d w/parentId %d\n",getpid(),getppid());	
	    }	    	    
    }
    return 0;
}
