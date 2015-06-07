/*
The problem you are facing is the misunderstanding of sem_init() function. When you read the manual page you will see this:

The pshared argument indicates whether this semaphore is to be shared between the threads of a process, or between processes.
If you are done reading up to this point, you will think that the non-zero value of pshared will make the semaphore inter-process semaphore. However, this is wrong. You should continue reading and you'll understand that you have to locate the semaphore in a shared memory region. To do that, several functions can be used as you can see below:

If pshared is nonzero, then the semaphore is shared between processes, and should be located in a region of shared memory (see shm_open(3), mmap(2), and shmget(2)). (Since a child created by fork(2) inherits its parent's memory mappings, it can also access the semaphore.) Any process that can access the shared memory region can operate on the semaphore using sem_post(3), sem_wait(3), etc.
I find this approach as a more complicated approach than others, therefore I want to encourage people to use sem_open() instead of sem_init().

Below you can see a complete program illustrates the following:

How to allocate shared memory and use shared variables between forked processes.
How to initialize a semaphore in a shared memory region and is used by multiple processes.
How to fork multiple processes and make the parent wait until all of its children exit.
*/

#include <stdio.h>          /* printf()                 */
#include <stdlib.h>         /* exit(), malloc(), free() */
#include <sys/types.h>      /* key_t, sem_t, pid_t      */
#include <sys/shm.h>        /* shmat(), IPC_RMID        */
#include <errno.h>          /* errno, ECHILD            */
#include <semaphore.h>      /* sem_open(), sem_destroy(), sem_wait().. */
#include <fcntl.h>          /* O_CREAT, O_EXEC          */


int main (int argc, char **argv){
    int i;                        /*      loop variables          */
    key_t shmkey;                 /*      shared memory key       */
    int shmid;                    /*      shared memory id        */
    sem_t *sem;                   /*      synch semaphore         *//*shared */
    pid_t pid;                    /*      fork pid                */
    int *p;                       /*      shared variable         *//*shared */
    unsigned int n;               /*      fork count              */
    unsigned int value;           /*      semaphore value         */

    /* initialize a shared variable in shared memory */
    shmkey = ftok ("/dev/null", 5);       /* valid directory name and a number */
    printf ("shmkey for p = %d\n", shmkey);
    shmid = shmget (shmkey, sizeof (int), 0644 | IPC_CREAT);
    if (shmid < 0){                           /* shared memory error check */
        perror ("shmget\n");
        exit (1);
    }

    p = (int *) shmat (shmid, NULL, 0);   /* attach p to shared memory */
    *p = 0;
    printf ("p=%d is allocated in shared memory.\n\n", *p);

    /********************************************************/

    printf ("How many children do you want to fork?\n");
    printf ("Fork count: ");
    scanf ("%u", &n);

    printf ("What do you want the semaphore value to be?\n");
    printf ("Semaphore value: ");
    scanf ("%u", &value);

    /* initialize semaphores for shared processes */
    sem = sem_open ("pSem", O_CREAT | O_EXCL, 0644, value); 
    /* name of semaphore is "pSem", semaphore is reached using this name */
    sem_unlink ("pSem");      
    /* unlink prevents the semaphore existing forever */
    /* if a crash occurs during the execution         */
    printf ("semaphores initialized.\n\n");


    /* fork child processes */
    for (i = 0; i < n; i++){
        pid = fork ();
        if (pid < 0)              /* check for error      */
            printf ("Fork error.\n");
        else if (pid == 0)
            break;                  /* child processes */
    }


    /******************************************************/
    /******************   PARENT PROCESS   ****************/
    /******************************************************/
    if (pid != 0){
        /* wait for all children to exit */
        while (pid = waitpid (-1, NULL, 0)){
            if (errno == ECHILD)
                break;
        }

        printf ("\nParent: All children have exited.\n");

        /* shared memory detach */
        shmdt (p);
        shmctl (shmid, IPC_RMID, 0);

        /* cleanup semaphores */
        sem_destroy (sem);
        exit (0);
    }

    /******************************************************/
    /******************   CHILD PROCESS   *****************/
    /******************************************************/
    else{
        sem_wait (sem);           /* P operation */
        printf ("  Child(%d) is in critical section.\n", i);
        sleep (1);
        *p += i % 3;              /* increment *p by 0, 1 or 2 based on i */
        printf ("  Child(%d) new value of *p=%d.\n", i, *p);
        sem_post (sem);           /* V operation */
        exit (0);
    }
}
OUTPUT

./a.out 
shmkey for p = 84214791
p=0 is allocated in shared memory.

How many children do you want to fork?
Fork count: 6 
What do you want the semaphore value to be?
Semaphore value: 2
semaphores initialized.

  Child(0) is in critical section.
  Child(1) is in critical section.
  Child(0) new value of *p=0.
  Child(1) new value of *p=1.
  Child(2) is in critical section.
  Child(3) is in critical section.
  Child(2) new value of *p=3.
  Child(3) new value of *p=3.
  Child(4) is in critical section.
  Child(5) is in critical section.
  Child(4) new value of *p=4.
  Child(5) new value of *p=6.

Parent: All children have exited.
It is not bad to check shmkey since when ftok() fails, it returns -1. However if you have multiple shared variables and if the ftok() function fails multiple times, the shared variables that have a shmkey with value -1 will reside in the same region of the shared memory resulting in a change in one affecting the other. Therefore the program execution will get messy. To avoid this, it is better checked if the ftok() returns -1 or not (better to check in source code rather than printing to screen like I did, although I wanted to show you the key values in case there is a collision).

Pay attention to how the semaphore is declared and initialized. It's different than what you have done in the question (sem_t sem vs sem_t* sem). Moreover, you should use them as they appear in this example. You cannot define sem_t* and use it in sem_init().
