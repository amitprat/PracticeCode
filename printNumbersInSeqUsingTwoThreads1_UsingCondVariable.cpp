#include	<iostream>
#include    <stdio.h>
#include	<pthread.h>
#include	<algorithm>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
bool turn = true;

void *print_even(void *data)
{
	int limit = *(int *)data;

	for(int i=0;i<=limit;i +=2)
	{
		pthread_mutex_lock(&mutex);
		while(!turn)
			pthread_cond_wait(&cond,&mutex);
		cout << i << "\t";
		turn = !turn;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
}
void *print_odd(void *data)
{
	int limit = *(int *)data;

	for(int i=1;i<=limit;i +=2)
	{
		pthread_mutex_lock(&mutex);
		while(turn)
			pthread_cond_wait(&cond,&mutex);
		cout<< i << endl;
		turn = !turn;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
	}
}

int main()
{
	pthread_t t1;
	pthread_t t2;
	int Num = 100;
	pthread_create(&t1,NULL,print_even,&Num);
	pthread_create(&t2,NULL,print_odd,&Num);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
    cout<<endl;
	return 0;
}

/*
Using Single function - print instead of printEven, printOdd 
As each thread has its own stack, so having same function for different thread or multiple function does
not make any difference. Each thread will keep its own copy of local variable and thread control block.

#include	<iostream>
#include    <stdio.h>
#include	<pthread.h>
#include	<algorithm>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
bool turn = true;
int limit = 100;
void *print(void *data)
{
    int count;
    int iseven = *(bool *)data;

    if(iseven)  count = 0;
    else count = 1;
    
    while(count <= limit) {
        pthread_mutex_lock(&mutex);
        if(iseven)  {
            while(!turn)
                pthread_cond_wait(&cond,&mutex);
        }else {
            while(turn)
                pthread_cond_wait(&cond,&mutex);
        }
        cout<<count<<"\t";
        count +=2;
        turn = !turn;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
	pthread_t t1, t2;
	int iseven = 1, isodd = 0;
	pthread_create(&t1,NULL,print,(void *)&iseven);
	pthread_create(&t2,NULL,print,(void *)&isodd);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
    cout<<endl;
	return 0;
}
*/

/*
Option  - 3

Using Two mutex lock instead of condtional variable.
It will take the sequential locks to avoid any deadlock


#include	<iostream>
#include    <stdio.h>
#include	<pthread.h>
#include	<algorithm>

using namespace std;

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
bool turn = true;
int limit = 100;
void *print_even(void *)
{
    int count = 0;
    while(count <= limit) {
        pthread_mutex_lock(&mutex1);
        cout<<count<<"\t";
        count +=2;
        pthread_mutex_unlock(&mutex2);
    }
}
void *print_odd(void *)
{
    int count = 1;
    while(count <= limit) {
        pthread_mutex_lock(&mutex2);
        cout<<count<<"\t";
        count +=2;
        pthread_mutex_unlock(&mutex1);
    }
}
int main()
{
	pthread_t t1, t2;
    pthread_mutex_lock(&mutex2); //odd print thread is already blocked here
	pthread_create(&t1,NULL,print_odd,NULL);
	pthread_create(&t2,NULL,print_even,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_unlock(&mutex1);
    cout<<endl;
	return 0;
}
*/
