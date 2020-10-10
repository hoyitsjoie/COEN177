/*
# Name: Joy Zou 
# Date: TH 9:15 | 10/1/2020
# Title: Lab2 – Step 6
# Description: This program uses pthreads to create two thread processes that perform the same functionality as step 1
*/
#include <stdio.h>      /* printf, stderr */
#include <sys/types.h>  /* pid_t */
#include <unistd.h>     /* fork */
#include <stdlib.h>     /* atoi */
#include <errno.h>      /* errno */
#include <pthread.h>
/* main function with command-line arguments to pass */


void *myThreadFun(void *arg)
{
    int i;
    sleep(1);
    for(i=0;i<100;i++){
    	printf("Thread %d on loop %d \n",*((int *)arg),i);
	usleep(300);
    }
    return NULL;
}

int main(int argc, char *argv[]) {   
    pthread_t id1, id2;
    int i=1;
    int j=2;
    int n = atoi(argv[1]); // n microseconds to input from keyboard for delay
    printf("\n Before thread calls.\n");
    pthread_create(&id1, NULL, myThreadFun,(void *) &i);
    pthread_create(&id2, NULL, myThreadFun,(void *) &j);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    return 0;
}
