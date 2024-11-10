#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_rwlock_t lock;

void* leitor(void* arg) {
    pthread_rwlock_rdlock(&lock);
    printf("Leitor %ld está lendo.\n", (long)arg);
    sleep(2);
    printf("Leitor %ld terminou de ler.\n", (long)arg);
    pthread_rwlock_unlock(&lock);
    return NULL;
}

void* escritor(void* arg) {
    pthread_rwlock_wrlock(&lock);
    printf("Escritor %ld está escrevendo.\n", (long)arg);
    sleep(2); 
    printf("Escritor %ld terminou de escrever.\n", (long)arg);
    pthread_rwlock_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[5];
    pthread_rwlock_init(&lock, NULL);

    for (long i = 0; i < 3; i++) pthread_create(&threads[i], NULL, leitor, (void*)i);
    for (long i = 3; i < 5; i++) pthread_create(&threads[i], NULL, escritor, (void*)i);

    for (int i = 0; i < 5; i++) pthread_join(threads[i], NULL);
    pthread_rwlock_destroy(&lock);

    return 0;
}
