#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
int condition_met = 0;

void* wait_for_signal(void* arg) {
    pthread_mutex_lock(&mutex);
    while (!condition_met) {
        printf("Thread aguardando pelo sinal...\n");
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Sinal recebido! Condição atendida.\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* send_signal(void* arg) {
    pthread_mutex_lock(&mutex);
    condition_met = 1;
    printf("Enviando sinal para thread aguardando...\n");
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, wait_for_signal, NULL);
    pthread_create(&t2, NULL, send_signal, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
