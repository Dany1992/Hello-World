#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int global = 0;
void *codiceThread1(void *args){
	int c = 5;
	global = global+c;
}

void *codiceThread2(void *args){
	int c = 10;
	global = c + global;
}

void main(){
	pthread_t th1,th2;
	printf("La variabile prima dei thread: %d\n", global);
	if((pthread_create(&th1,NULL,codiceThread1,"1")) < 0){
		printf("errore nella creazione del thread\n");
		pthread_exit(1);
	}
	if ((pthread_create(&th2,NULL,codiceThread2,"2")) < 0){
		printf("errore nella creazione del thread\n");
		pthread_exit(1);
	}
	int ret = pthread_join(th1,NULL);
	int ret1 = pthread_join(th2,NULL);
	printf("ret: %d\n",ret);
	printf("ret1: %d\n",ret1);
	printf("La variabile dopo la creazione dei thread: %d\n",global);
}