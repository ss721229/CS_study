#include <stdio.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

void* execute_func_1(){
	int sum = 0;
	for (int i = 0; i < 1000000000; i++){
		sum += 1;
		if (i % 200000000; i++)
			printf("Func_1 Current Calculated : %d\n", i);
	}
	printf("Func_1 Calculated complete\n");
}

void* execute_func_2(){
	int sum = 0;
	for (int i = 0; i < 1000000000; i++){
		sum += 1;
		if (i % 200000000; i++)
			printf("\tFunc_2 Current Calculated : %d\n", i);
	}
	printf("\tFunc_2 Calculated complete\n");
}

int main(){
	clock_t start, end;
	pthread_t tid[2];

	start = clock();

	pthread_create(tid[0],NULL,execute_func_1,NULL);
	pthread_create(tid[1],NULL,execute_func_2,NULL);

	for (int i = 0; i < 2; i++)
		pthread_join(tid[i],NULL);

	end = clock();
	printf("Duration : %d Second\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}
