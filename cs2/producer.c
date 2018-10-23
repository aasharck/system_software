#include<stdio.h>
#include<stdlib.h>

int mutex=1,empty=3,full=0,x=0;
int wait(int s);
int signal(int s);
void producer();
void consumer();

int main(){
	int n;
	while(1)
	{
	printf("\n Enter your option!\n 1.Producer\n 2.Consumer \n 3.Exit\n");
	scanf("%d", &n);
	switch(n){
		case 1: if((mutex == 1)&&(empty!=0))
				producer();
			else
				printf("\nbuffer full\n");
			break;
		case 2: if((mutex == 1)&&(full!=0))
				consumer();
			else
				printf("\nempty\n");
			break;
		case 3: exit(0);
			break;
		}
	}
	return 0;
}
	int signal(int s){
		return ++s;
	}
	int wait(int s){
		return --s;
	}
	void producer(){
		mutex = wait(mutex);
		full = signal(full);
		empty = wait(empty);
		x++;
		printf("\n Item produced is %d \n",x);
		mutex = signal(mutex);
	}
	 void consumer(){
                mutex = wait(mutex);
                full = wait(full);
                empty = signal(empty);
                x--;
                printf("\n Item consumed is %d \n",x);
                mutex = signal(mutex);
        }

