#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_func(void *arg) {
    printf("Thread created\n");
    printf("Thread exiting...\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    int ret;

    printf("Main thread\n");

    // Create a new thread
    ret = pthread_create(&thread, NULL, thread_func, NULL);
    if (ret != 0) {
        fprintf(stderr, "Failed to create thread\n");
        return 1;
    }

    // Wait for the thread to terminate
    ret = pthread_join(thread, NULL);
    if (ret != 0) {
        fprintf(stderr, "Failed to join thread\n");
        return 1;
    }

    printf("Thread terminated\n");

    return 0;
}

