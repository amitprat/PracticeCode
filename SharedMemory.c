// write.c

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() {

  key_t key=1235;
  int shm_id;
  void *shm;

  int *ptr = 83838;

  shm_id = shmget(key,10,IPC_CREAT | 0666);
  shm = shmat(shm_id,NULL,NULL);

  sprintf(shm,"%d",ptr);

  printf("Address is %p, Value is %p \n", (void *)shm, (void *)&ptr);
  printf("Shm value is %d \n", *(int *)shm);
  return;
}

//read.c

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  key_t key=1235;
  int shm_id;
  void *shm;

  int *p = (int *)malloc(sizeof(int));
  shm_id = shmget(key,10,NULL);
  shm = shmat(shm_id,NULL,NULL);
  if(shm == NULL)
  {
    printf("error");
  }
  sscanf(shm,"%d",p);
  printf("Address is %p %p %p %d\n",(void *)shm, (void *)p, (void *)&p, *p);
  printf("Shared value is %d \n", *(int *)shm);
  return 0;
}
