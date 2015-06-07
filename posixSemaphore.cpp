/*
This program demonstrates the use of semaphores to solve the critical region problem.

int sem_init(sem_t *sem, int pshared, unsigned int value);

The sem_init() function is used to initialize the semaphore's value. The pshared argument must be 0 for semaphores local to a process.
int sem_wait(sem_t * sem);

The sem_wait() function performs the equivalent of the down semaphore operation.
int sem_post(sem_t * sem);

The sem_post() function performs the equivalent of the up semaphore operation.
int sem_destroy(sem_t * sem);

The sem_destroy() function is used to properly deallocate resources alloted to a semaphore. The semaphore in this program is used as a mutex, a binary semaphore, to implement mutual exclusion between two processes which use a shared resource.
To compile and link the program:

gcc -o sem-ex sem-ex.c -Wall -Werror -lpthread
sem-ex.c (download)


----------------
sem_init()
-----------------
       #include <semaphore.h>

       int sem_init(sem_t *sem, int pshared, unsigned int value);

       Link with -pthread.
DESCRIPTION         top

       sem_init() initializes the unnamed semaphore at the address pointed
       to by sem.  The value argument specifies the initial value for the
       semaphore.

       The pshared argument indicates whether this semaphore is to be shared
       between the threads of a process, or between processes.

       If pshared has the value 0, then the semaphore is shared between the
       threads of a process, and should be located at some address that is
       visible to all threads (e.g., a global variable, or a variable
       allocated dynamically on the heap).

       If pshared is nonzero, then the semaphore is shared between
       processes, and should be located in a region of shared memory (see
       shm_open(3), mmap(2), and shmget(2)).  (Since a child created by
       fork(2) inherits its parent's memory mappings, it can also access the
       semaphore.)  Any process that can access the shared memory region can
       operate on the semaphore using sem_post(3), sem_wait(3), and so on.
       (i.e. if sharedVal = 1, then the sem_t mutex should be written to shared memory
       sprintf(sharedMem,"%d",mutex);)

       Initializing a semaphore that has already been initialized results in
       undefined behavior.
RETURN VALUE         top
       sem_init() returns 0 on success; on error, -1 is returned, and errno
       is set to indicate the error.
       
-------------------------
sem_wait
-------------------------
       int sem_wait(sem_t *sem);
       
       sem_wait() decrements (locks) the semaphore pointed to by sem.  If
       the semaphore's value is greater than zero, then the decrement
       proceeds, and the function returns, immediately.  If the semaphore
       currently has the value zero, then the call blocks until either it
       becomes possible to perform the decrement (i.e., the semaphore value
       rises above zero), or a signal handler interrupts the call.
--------------------------
sem_trywait
--------------------------
       int sem_trywait(sem_t *sem);
        
        sem_trywait() is the same as sem_wait(), except that if the decrement
       cannot be immediately performed, then call returns an error (errno
       set to EAGAIN) instead of blocking.
-------------------------------------------
sem_timedwait
------------------------------------------------------------
       int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);

        sem_timedwait() is the same as sem_wait(), except that abs_timeout
       specifies a limit on the amount of time that the call should block if
       the decrement cannot be immediately performed.  The abs_timeout
       argument points to a structure that specifies an absolute timeout in
       seconds and nanoseconds since the Epoch, 1970-01-01 00:00:00 +0000
       (UTC).  This structure is defined as follows:

           struct timespec {
               time_t tv_sec;      /* Seconds */
               long   tv_nsec;     /* Nanoseconds [0 .. 999999999] */
           };

       If the timeout has already expired by the time of the call, and the
       semaphore could not be locked immediately, then sem_timedwait() fails
       with a timeout error (errno set to ETIMEDOUT).

       If the operation can be performed immediately, then sem_timedwait()
       never fails with a timeout error, regardless of the value of
       abs_timeout.  Furthermore, the validity of abs_timeout is not checked
       in this case.

       Link with -pthread.

   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       sem_timedwait(): _POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600
       
    Return Val - 
    Above all return 0 on success and -1 on failure setting the ERRNO
*/
/* Includes */
#include <unistd.h>     /* Symbolic Constants */
#include <sys/types.h>  /* Primitive System Data Types */ 
#include <errno.h>      /* Errors */
#include <stdio.h>      /* Input/Output */
#include <stdlib.h>     /* General Utilities */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */

/* prototype for thread routine */
void handler ( void *ptr );

/* global vars */
/* semaphores are declared global so they can be accessed 
   in main() and in thread routine,
   here, the semaphore is used as a mutex */
sem_t mutex;
int counter; /* shared variable */

int main()
{
    int i[2];
    pthread_t thread_a;
    pthread_t thread_b;
    
    i[0] = 0; /* argument to threads */
    i[1] = 1;
    
    sem_init(&mutex, 0, 1);      /* initialize mutex to 1 - binary semaphore */
                                 /* second param = 0 - semaphore is local */
    /*
        firsstArg - seg_t segId;
        secondArg - 0 - if shared among threads,
                    1 - if shared among process
                        then the 
    */
    /* Note: you can check if thread has been successfully created by checking return value of
       pthread_create */                                 
    pthread_create (&thread_a, NULL, (void *) &handler, (void *) &i[0]);
    pthread_create (&thread_b, NULL, (void *) &handler, (void *) &i[1]);
    
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);

    sem_destroy(&mutex); /* destroy semaphore */
                  
    /* exit */  
    exit(0);
} /* main() */

void handler ( void *ptr )
{
    int x; 
    x = *((int *) ptr);
    printf("Thread %d: Waiting to enter critical region...\n", x);
    sem_wait(&mutex);       /* down semaphore */
    /* START CRITICAL REGION */
    printf("Thread %d: Now in critical region...\n", x);
    printf("Thread %d: Counter Value: %d\n", x, counter);
    printf("Thread %d: Incrementing Counter...\n", x);
    counter++;
    printf("Thread %d: New Counter Value: %d\n", x, counter);
    printf("Thread %d: Exiting critical region...\n", x);
    /* END CRITICAL REGION */    
    sem_post(&mutex);       /* up semaphore */
    
    pthread_exit(0); /* exit thread */
}

Links
Linux Tutorial: POSIX Threads
Getting Started With POSIX Threads
