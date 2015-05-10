#include  <stdio.h>
#include  <sys.types.h>
#include  <stdlib.h>
#include  <string.h>
#include  <unistd.h>

int main()
{
  int fd[2];
  if( !pipe(fd) ) exit(1);
  
  pid_t id = fork();
  if(id < 0) {
    close(fd[0]);
    close(fd[1]);
    exit(1);
  }
  
  if( id == 0 ) {
    close(fd[0]);
    dup2( fd[1], STDOUT ); //it duplicates STDOUT to fd[1] and deletes fd[1]
    printf("Say something...\n"); // it will be written fd[1]
  }
  else
  {
    close(fd[1]);
    dup2(fd[0],STDIN); //it also duplicates same as above
    char buffer[32];
    scanf("%s",buffer); //it reads from fd[0] - as written by its parent
  }
}
