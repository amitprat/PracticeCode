#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#define READ_END 0
#define WRITE_END 1
#define BUFFER_SIZE 32
int main()
{
    pid_t id;
    int fd[2];
    char buffer[BUFFER_SIZE];
    char output[] = "Hello World!!";
    if( !pipe(fd) ) {
        printf("pipe creation failed!! \n");
        exit(1);
    }
     id = fork();
     if(id < 0 ) {
        printf("fork failed");
        exit(1);
     }

     if(id == 0) //child process
     {
         close(fd[WRITE_END]);
         read(fd[READ_END],buffer,BUFFER_SIZE);
         printf("child read : %s \n",buffer);
         close(fd[READ_END]);
     }
     else
     {
         close(fd[READ_END]);
         write(fd[WRITE_END],output,BUFFER_SIZE);
         close(fd[WRITE_END]);
     }
    return 0;
}

