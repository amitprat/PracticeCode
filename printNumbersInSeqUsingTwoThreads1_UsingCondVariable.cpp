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
