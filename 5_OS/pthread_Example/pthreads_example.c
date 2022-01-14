#include <pthread.h> 
#include <stdio.h>
#define NUM_THREADS (sizeof(threadParam)/sizeof(long))

long threadParam[] = {1,8,19,23,27};

void *PrintHello(void *threadId){
    long *data = (long*)threadId; 
    printf("Hello World! I am #%ld\n", *data);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    printf("The size of the array thread param is: %ld \n", sizeof(threadParam));
    printf("The size of long in this system is: %ld \n", sizeof(long));
    printf("The size of the array is: %ld", NUM_THREADS);


    /*pthread_t - The data type used to uniquely identify a thread. It is returned by * pthread_create() and used by the application in function calls that require a   thread identifier.
    */
    pthread_t threads[NUM_THREADS]; 

    for(int i = 0; i < NUM_THREADS ; i++){
        pthread_create(&threads[i], NULL, PrintHello, threadParam + i);
    }

    for(int i = 0; i < NUM_THREADS ; i++){
        pthread_join(threads[i], NULL);
    }
    return 0;
}

