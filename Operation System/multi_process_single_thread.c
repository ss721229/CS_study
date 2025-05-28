#include <stdio.h>
#include <time.h>
#include <pthread.h>

void execute_func_1(){
	int sum = 0;
	for (int i=0; i<1000000000; i++){
		sum += 1;
		if(i % 200000000 == 0)
			printf("Func_1 Current Calcutalted : %d\n", i);
	}
	printf("Func_1 Calculate Complete\n");
}

void execute_func_2(){
	int sum = 0;
	for (int i=0; i<1000000000; i++){
		sum += 1;
		if(i % 200000000 == 0)
			printf("\tFunc_2 Current Calcutalted : %d\n", i);
	}
	printf("\tFunc_2 Calculate Complete\n");
}

int main() {
    clock_t start, end;
    pid_t pid = fork();

    start = clock();

    printf("pid : %d\n", pid);
    if (pid == 0){ // child process
        execute_func_1();
        return 0;
    }
    else{ // parent process
        execute_func_2();

        int status;
        waitpid(pid, &status, 0);
    }

    end = clock();
    printf("Duration : %f Second\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}