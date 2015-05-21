/*
There are three threads in a process. 
The first thread prints 1 1 1 …, the second one prints 2 2 2 …, and the third one prints 3 3 3 … endlessly. 
How do you schedule these three threads in order to print 1 2 3 1 2 3 …?
*/
#include    <iostream>
#include    <pthread.h>
using namespace std;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;

void *func1(void *arg) {
    int num = *(int *)arg;
    int count =0;
    while(count<20) {
        pthread_mutex_lock(&mutex1);
        cout<<num<<" ";
        count++;
        pthread_mutex_unlock(&mutex2);
    }
}
void *func2(void *arg) {
    int num = *(int *)arg;
    int count =0;
    while(count<20) {
        pthread_mutex_lock(&mutex2);
        cout<<num<<" ";
        count++;
        pthread_mutex_unlock(&mutex3);
    }
}
void *func3(void *arg) {
    int num = *(int *)arg;
    int count =0;
    while(count<20) {
        pthread_mutex_lock(&mutex3);
        cout<<num<<" ";
        count++;
        pthread_mutex_unlock(&mutex1);
    }
}

int main()
{
    pthread_t tid1,tid2,tid3;
    int n1=1,n2=2,n3=3;
    pthread_mutex_lock(&mutex2);
    pthread_mutex_lock(&mutex3);
    pthread_create(&tid1,NULL,func1,(void *)&n1);
    pthread_create(&tid2,NULL,func2,(void *)&n2);
    pthread_create(&tid3,NULL,func3,(void *)&n3);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);

    return 0;
}
