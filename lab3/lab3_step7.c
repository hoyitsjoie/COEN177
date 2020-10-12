/*
 * # Name: Joy Zou 
 * # Date: TH 9:15 | 10/11/2020
 * # Title: Lab3 – Step 7
 * # Description: This pthread program solves a bug where some threads print out the same value of i 
 * */
/**************************
*       COEN177: Threads  *
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *go(void *);
#define NTHREADS 10

int t[10];

pthread_t threads[10];
int main() {
    int i;
    int j;
    for (i = 0; i < NTHREADS; i++)  
        pthread_create(&threads[i], NULL, go,(void*)(size_t)i);
	//sleep(1);
    for (j = 0; j < NTHREADS; j++) {
//	printf("Thread %d returned\n", i);
        pthread_join(threads[j],NULL);
	printf("thread %d returned\n", j);
    }
    printf("Main thread done.\n");
    return 0;
}
void *go(void *arg) {
 printf("Hello from thread %d with iteration %d\n",  (int)pthread_self(), (int*)(size_t*)arg);
 sleep(1);
 return 0;
}


