#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

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

void* thread_func_1(void* arg) {
    execute_func_1();
    return NULL;
}

void* thread_func_2(void* arg) {
    execute_func_2();
    return NULL;
}

void run_threads() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_func_1, NULL);
    pthread_create(&t2, NULL, thread_func_2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
}

int main() {
    clock_t start, end;
    pid_t pid = fork();
    
    start = clock();

    printf("pid : %d\n", pid);
    if (pid == 0){ // child process
        run_threads();
        exit(0);
    }
    else{ // parent process
        run_threads();

        int status;
        waitpid(pid, &status, 0);
    }
    
    end = clock();
    printf("Total Duration: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
