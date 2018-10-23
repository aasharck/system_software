#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int buf[5],f,r;
sem_t mutex, full,empty;

void *producer(void *arg)
{
	int i;
	for(i=0; i<5; i++){
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("produced item is %d \n",i);
		buf[(++r)%5]=i;
		if((r%5) ==f)
			printf("full \n");
		sleep(1);
		sem_post(&mutex);
		sem_post(&full);
		
		}
}

void *consumer(void *arg)
{
	int i,item;
	for(i=0; i<5; i++){
		sem_wait(&full);
		sem_wait(&mutex);
		item = buf[(++f)%5];
		printf("consumed item is %d \n",item);
		if(r==f)
			printf("empty \n");		
		sleep(1);
		sem_post(&mutex);
		sem_post(&empty);
		}
}
main(){
	pthread_t tid1, tid2;
	sem_init(&mutex,0,1);
	sem_init(&full,0,1);
	sem_init(&empty,0,5);
	pthread_create(&tid1,NULL,producer,NULL);
	pthread_create(&tid2,NULL,consumer,NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}
