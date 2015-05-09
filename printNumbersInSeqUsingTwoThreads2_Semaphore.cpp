#include <stdio.h> 
#include <iostream>
#include <pthread.h> 
#include <stdlib.h> 
#include <semaphore.h> 
using namespace std;


int glob = 0; 
sem_t mutex1; 
sem_t mutex2; 

void *function1(void *) 
{ 
  int count1 = 0; 
  while(count1 < 100){ 
    sem_wait(&mutex1); 
    glob ++; 
    printf("%d \n", glob); 
    sem_post(&mutex2); 
    count1+=2; 
  } 
} 


void *function2(void *) 
{ 
    int count1 = 0; 
    while(count1 < 100){ 
        sem_wait(&mutex2); 
        glob ++; 
        printf("%d \n", glob); 
        sem_post(&mutex1); 
        count1+=2; 
    } 
} 


main() 
{ 
    int rc1, rc2; 
    pthread_t thread1, thread2; 


    sem_init(&mutex1, 0, 1); 
    sem_init(&mutex2, 0, 0); 

    /* Create independent threads each of which will execute functionC */ 

    if( (rc1=pthread_create( &thread1, NULL, &function1, NULL)) ) 
    { 
        printf("Thread creation failed: %d\n", rc1); 
    } 

    if( (rc2=pthread_create( &thread2, NULL, &function2, NULL)) ) 
    { 
        printf("Thread creation failed: %d\n", rc2); 
    } 

    /* Wait till threads are complete before main continues. Unless we */ 
    /* wait we run the risk of executing an exit which will terminate */ 
    /* the process and all threads before the threads have completed. */ 

    pthread_join( thread1, NULL); 
    pthread_join( thread2, NULL); 

    exit(0); 
}
