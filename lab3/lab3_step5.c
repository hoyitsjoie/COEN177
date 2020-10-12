/*
 * # Name: Joy Zou 
 * # Date: TH 9:15 | 10/11/2020
 * # Title: Lab3 – Step 5
 *Description: This Program uses a pipe to implement a solution for the produce consumer problem
 * /
**************************
*   Lab3 - pipe()
**************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/wait.h> 

#define SIZE_BUFFER 20

void producer(int fds){
   int i;
   for(i=0;i<SIZE_BUFFER;i++){
  	 write(fds, &i, sizeof i);
         usleep(60000);
   }
   exit(0);
}

void consumer(int fds){
   int count, i;
   while((count=read(fds,&i,sizeof i))>0){
	printf("consumer reads %d\n", i);
   }
   exit(0);    
}

// main
int main(int argc,char *argv[]){
   int  fds[2];
   char buff[60];
   int count;
   int i;
   pipe(fds);
   
   if (fork()==0){
       printf("\nWriter on the upstream end of the pipe -> %d arguments \n",argc);
       close(fds[0]);
       producer(fds[1]);
   }
   else if(fork()==0){
       printf("\nReader on the downstream end of the pipe \n");
       close(fds[1]);
       consumer(fds[0]);
    //   exit(0);
    }
   else{     
      close(fds[0]);
      close(fds[1]);
      wait(0);
      wait(0);
   }
return 0;
}
