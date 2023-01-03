# Study tour in a museum


**_A museum arranged a day long program for some school children in which students can
participate in various activities. In one room, a 3D short movie has been shown and so
3D glasses are needed. Also, after they have watched the movie, they need to return the
3D glasses. However, only a limited number of 3D glasses are available. So, all
students may not be able to watch it at the same time. Some students have to wait
unless they get 3D glasses. If the waiting area is full, the other students have to leave.
using POSIX threads, mutex locks, and semaphores implement a solution that
synchronizes the activities of the students. The total number of students, the number of
3D glasses are passed as command line arguments. Once a student thread finish
watching the movie, it should terminate. Once all the student threads are terminated, the
main program should be terminated. Your program should work for any number of
students and 3D glasses. Allocate memory for data structures dynamically based on the
input parameter(s)._**

## Build And Run

you can build the code by running the following command:

```bash
gcc -o museum_program museum_program.c -lpthread
```
To run the code with input, you can use the following command:

```bash
./museum_program num_students num_glasses
```
Suppose you have 5 students and 3 glasses, you must follow the command:
```bash
./museum_program 5 3
```


# Code Explanation

The first part includes the necessary header files and defines the size of the waiting room:

```c
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define WAITING_ROOM_SIZE 10
```

The next part declares the global variables that will be used in the program:

```c
int num_students;
int num_glasses;
int waiting_room_count = 0;
pthread_mutex_t waiting_room_lock;
sem_t glasses;
```

- **`num_students`** and **`num_glasses`** are the number of students and 3D glasses passed as command line arguments.
- **`waiting_room_count`** is a counter for the number of students in the waiting room.
- **`waiting_room_lock`** is a mutex lock to synchronize access to the waiting room.
- **`glasses`** is a semaphore to keep track of the number of available 3D glasses.

The **`student_activity`** function is the thread function that represents the activity of a student. It takes a student ID as an argument:

```c
void* student_activity(void* arg) {
```

The first thing the student does is wait for a 3D glass to be available:

```c
// Wait for a 3D glass to be available
    sem_wait(&glasses);
```

Then, the student tries to enter the waiting room. To do this, it first locks the mutex lock to synchronize access to the waiting room:

```c
// Lock the waiting room
    pthread_mutex_lock(&waiting_room_lock);
```

Then, it increments the waiting room counter and prints a message indicating that the student has entered the waiting room:

```c
// Enter the waiting room
    waiting_room_count++;
    printf("Student %ld entered the waiting room, waiting room count = %d\n", (long)arg, waiting_room_count);
```

After that, the student unlocks the mutex lock:

```c
// Unlock the waiting room
    pthread_mutex_unlock(&waiting_room_lock);
```

The student then waits for the movie to start:

```c
// Wait for the movie to start
    sleep(5);
```

When the movie is over, the student leaves the waiting room. It locks the mutex lock again, decrements the waiting room counter, and prints a message indicating that the student has left the waiting room:

```c
// Lock the waiting room
pthread_mutex_lock(&waiting_room_lock);
// Leave the waiting room
waiting_room_count--;
printf("Student %ld left the waiting room, waiting room count = %d\n", (long)arg, waiting_room_count);
```

The student then unlocks the mutex lock and returns the 3D glass:

```c
// Unlock the waiting room
pthread_mutex_unlock(&waiting_room_lock);

// Return the 3D glass
sem_post(&glasses);
```

After returning the 3D glass, the student terminates its thread:

```c
// Terminate the thread
    pthread_exit(NULL);
}
```

In the **`main`** function, the first thing we do is parse the command line arguments and initialize the global variables:

```c
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
```

Then, we create an array of student threads and start them:

```c
// Create an array of student threads
    pthread_t students[num_students];
    for (long i = 0; i < num_students; i++) {
        if (pthread_create(&students[i], NULL, student_activity, (void*)i) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }
```

We wait for all student threads to terminate:

```c
// Wait for all student threads to terminate
    for (int i = 0; i < num_students; i++) {
        if (pthread_join(students[i], NULL) != 0) {
            perror("Error waiting for thread");
            return 1;
        }
    }
```

Finally, we destroy the semaphore and mutex lock and return from the main function:

```c
// Destroy the semaphore and mutex lock
    sem_destroy(&glasses);
    pthread_mutex_destroy(&waiting_room_lock);

    return 0;
}
```
