/*
Project Title: Movie Ticketing System
Project Description: Star Cineplex is the first multiplex cinema theatre in Bangladesh. It also gives its viewers the facility to check available tickets and book shows via online ticket booking system. When the program is run, it creates a certain number of threads that attempt to sell all available tickets. However, the program needs to make sure that while booking the same show by various users, the total number of available seats are error free and there is not any data loss.
Using POSIX threads, mutex locks, and semaphores implement a solution that synchronizes the activities of the users. The total number of users, the number of tickets, and number of shows are passed as command line arguments. Once a user thread finishes booking a show, it should terminate. Once all the user threads are terminated, the main program should be terminated. Your program should work for any number of users, tickets and shows. Allocate memory for data structures dynamically based on the input parameter(s).
*/
#include <stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include<time.h>

sem_t m;
pthread_t *t1;

struct show{
	int total;
};

struct show *movie;

struct user{
	int total;
};

struct user cus;



void* buying(void *arg)
{
    ///wait
    sem_wait(&m);

    ///critical section
    sleep(2);
	srand(time(0));
	int sh = rand()%5;  ///random num is creating, so that users can choose random movies
	printf("\n\nUser %d Buying Tickets From Show %d\n",(int *)arg,sh);
	printf("Tickets available on Show %d : %d\n",sh,movie[sh].total);
	int ticketUserNeed = rand()%7;

	///when user buys tickets, it is subtracted from total tickets
	if(movie[sh].total>=ticketUserNeed){
		movie[sh].total-=ticketUserNeed;
		printf("User %d Buy %d Tickets \n",(int *)arg,ticketUserNeed);
		printf("Tickets available on Show %d : %d\n",sh,movie[sh].total);
	}

	///if there are no available tickets i.e if all tickets are sold out then user can't buy
	else{
		printf("User %d can't Buy %d Tickets \n",(int *)arg,ticketUserNeed);
		printf("Tickets available on Show %d : %d\n",sh,movie[sh].total);
	}

    ///signal
    printf("User %d is exiting queue \n",(int *)arg);
    sem_post(&m);
}


void* create_seller(int user){
    sem_init(&m, 0, 10);  ///here 10 is an unsigned integer which denotes as semaphore

    pthread_create(&t1[user],NULL,buying,(int*)user);  ///thread with struct user is creating
    pthread_join(t1[user],NULL);

    sem_destroy(&m);
    return 0;

}

int main(int argc,char *argv[])  ///this is used for command line, for taking value form cmd
{
	int user=15,sh=5,tickets=10,i;
	//user = atoi(argv[1]);
	//sh = atoi(argv[2]);
	//tickets = atoi(argv[3]);

	movie = (show*) malloc(sh * sizeof(show));  ///dynamic memory allocation

	cus.total = user;
	t1 = (pthread_t*)malloc(cus.total*sizeof(pthread_t));


	for(i=0;i<sh;i++){
		movie[i].total = tickets;
	}
	printf("Total User: %d\n",user);
	printf("Total Show: %d\n",sh);
	printf("Total Ticket: %d\n",tickets);

	for(i=0;i<cus.total;i++){
		create_seller(i);
	}
    return 0;
}

