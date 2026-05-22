#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE], in = 0, out = 0, n;

sem_t empty, full;
pthread_mutex_t mutex;

void displayBuffer() {
    printf("Buffer: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

void *producer() {
    for(int i = 0; i < n; i++) {

        int item = rand() % 100;

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Produced: %d\n", item);

        in = (in + 1) % SIZE;

        displayBuffer();

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        sleep(1);
    }
}

void *consumer() {
    for(int i = 0; i < n; i++) {

        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = buffer[out];
        printf("Consumed: %d\n", item);

        out = (out + 1) % SIZE;

        displayBuffer();

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(1);
    }
}

int main() {

    pthread_t p, c;

    printf("Enter number of items: ");
    scanf("%d", &n);

    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
