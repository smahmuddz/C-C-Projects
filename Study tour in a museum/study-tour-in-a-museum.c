#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WAITING_ROOM_SIZE 10

int num_students;
int num_glasses;
int waiting_room_count = 0;
pthread_mutex_t waiting_room_lock;
sem_t glasses;

void* student_activity(void* arg) {
    // Wait for a 3D glass to be available
    sem_wait(&glasses);

    // Lock the waiting room
    pthread_mutex_lock(&waiting_room_lock);
    // Enter the waiting room
    waiting_room_count++;
    printf("Student %ld entered the waiting room, waiting room count = %d\n", (long)arg, waiting_room_count);
    // Unlock the waiting room
    pthread_mutex_unlock(&waiting_room_lock);

    // Wait for the movie to start
    sleep(5);

    // Lock the waiting room
    pthread_mutex_lock(&waiting_room_lock);
    // Leave the waiting room
    waiting_room_count--;
    printf("Student %ld left the waiting room, waiting room count = %d\n", (long)arg, waiting_room_count);
    // Unlock the waiting room
    pthread_mutex_unlock(&waiting_room_lock);

    // Return the 3D glass
    sem_post(&glasses);

    // Terminate the thread
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: museum_program num_students num_glasses\n");
        return 1;
    }

    num_students = atoi(argv[1]);
    num_glasses = atoi(argv[2]);

    // Initialize the semaphore with the number of available 3D glasses
    sem_init(&glasses, 0, num_glasses);
    // Initialize the mutex lock
    pthread_mutex_init(&waiting_room_lock, NULL);

    // Create an array of student threads
    pthread_t students[num_students];
    for (long i = 0; i < num_students; i++) {
        if (pthread_create(&students[i], NULL, student_activity, (void*)i) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }

    // Wait for all student threads to terminate
    for (int i = 0; i < num_students; i++) {
        if (pthread_join(students[i], NULL) != 0) {
            perror("Error waiting for thread");
            return 1;
        }
    }

    // Destroy the semaphore and mutex lock
    sem_destroy(&glasses);
    pthread_mutex_destroy(&waiting_room_lock);

    return 0;
}
