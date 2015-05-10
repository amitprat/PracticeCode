#include <stdio.h>
#include <sys/stat.h>
#include <sys/shm.h>

int main()
{
    int segId;
    const int size = 4096; // the size should be page aligned
    segId = shmget ( IPC_PRIVATE /*IPC_SHARED*/,  size, S_IRUSR | S_IWUSR );

    /*We can also pass the address and offset where the shared segment is need to be attached in process */
    char *sharedMem = (char *)shmat(segId,NULL,0); // passing NULL indicates to select the address by itself where the shared memory is need to be attached.

    sprintf(sharedMem, "Hi I am here");

    printf ( sharedMem );

    shmdt ( sharedMem );

    shmctl(segId,IPC_RMID, NULL);

    return 0;

}
