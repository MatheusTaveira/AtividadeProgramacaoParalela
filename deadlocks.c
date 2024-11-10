#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void* thread1_function(void* arg) {
    pthread_mutex_lock(&mutex1);
    printf("Thread 1 bloqueou mutex1\n");
    
    pthread_mutex_lock(&mutex2);
    printf("Thread 1 bloqueou mutex2\n");

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    return NULL;
}

void* thread2_function(void* arg) {
    pthread_mutex_lock(&mutex1);
    printf("Thread 2 bloqueou mutex1\n");
    
    pthread_mutex_lock(&mutex2);
    printf("Thread 2 bloqueou mutex2\n");

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);

    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    pthread_create(&t1, NULL, thread1_function, NULL);
    pthread_create(&t2, NULL, thread2_function, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}
