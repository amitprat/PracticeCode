#include <stdio.h>
#include <sys/stat.h>
#include <sys/shm.h>

int main()
{
    int segId;
    const int size = 4096; // the size should be page aligned
    segId = shmget ( IPC_PRIVATE /*IPC_SHARED*/,  size, S_IRUSR | S_IWUSR );
    //segId = shmet(key,size,IPC_CREAT|IPC_EXCL|S_IRUSR|S_IWUSR);
    /*
    IPC_CREAT—This flag indicates that a new segment should be created.This permits
    creating a new segment while specifying a key value.
    IPC_EXCL—This flag, which is always used with IPC_CREAT, causes shmget to fail
    if a segment key is specified that already exists.Therefore, it arranges for the calling
    process to have an “exclusive” segment. If this flag is not given and the key
    of an existing segment is used, shmget returns the existing segment instead of
    creating a new one.
    Mode flags—This value is made of 9 bits indicating permissions granted to
    owner, group, and world to control access to the segment. Execution bits are
    ignored.An easy way to specify permissions is to use the constants defined in
    <sys/stat.h> and documented in the section 2 stat man page.1 For example,
    S_IRUSR and S_IWUSR specify read and write permissions for the owner of the
    shared memory segment, and S_IROTH and S_IWOTH specify read and write permissions
    for others.
    */
    /*We can also pass the address and offset where the shared segment is need to be attached in process */
    char *sharedMem = (char *)shmat(segId,NULL,0); // passing NULL indicates to select the address by itself where the shared memory is need to be attached.
    /*
    segId - the segment id which is need to be attached
    secondArg - address in process at which shared memory is need to be attached.
        -passing NULL means process automatically chooses the available address.
    ThirdArg - Flag - SHM_RND, SHM_RDONLY
        -SHM_RND - specefies that the secondArgs (size) to be rounded to multiple of page size
        -SHM_RDONLY - specified that the attached address space is read only
    */
    
    struct shmid_ds shmBuffer;
    shmctl(segId,IPC_STAT,&shmBuffer);
    /*
        IPC_STAT - to get segment statistics
        IPC_RMID - to remove the segment,
            - If the segment has been deallocated and this was the last process using it, it is
            removed. Calls to exit and any of the exec family automatically detach segments
        Each shared memory segment should be explicitly deallocated using shmctl when
        you’re finished with it, to avoid violating the systemwide limit on the total number of
        shared memory segments. Invoking exit and exec detaches memory segments but
        does not deallocate them
    */
    int segSize = shmBuffer.shm_segSz;
    printf("Segment size : %d\n",segSize);
    sprintf(sharedMem, "Hi I am here");

    printf ( sharedMem );

    shmdt ( sharedMem );

    shmctl(segId,IPC_RMID, NULL);

    return 0;

}

/*
% ipcs -m
------ Shared Memory Segments --------
key shmid owner perms bytes nattch status
0x00000000 1627649 user 640 25600 0
If this memory segment was erroneously left behind by a program, you can use the
ipcrm command to remove it.
% ipcrm shm 1627649
*/
