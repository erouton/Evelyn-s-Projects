//********************************************************************
//
// Evelyn Routon
// Operating Systems
// Programming Project #3
// October 9, 2024
// Instructor: Dr. Siming Liu
//
//********************************************************************
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define N 100

sem_t sem_mutex;
void *runner(void *param);








int main(int argc, char *argv[])
{
  sem_init(&sem_mutex, 0, 1);

  pthread_t tid[N];
  pthread_attr_t attr;

  if (argc != 2)
  {
    printf("usage: a.out <integer valude>\n");
    return -1;
  }

  pthread_attr_init(&attr);
  for (int i = 0; i < N; i++)
  {
    pthread_create(&tid[i], &attr, runner, argv[1]);
  }
  for (int i = 0; i < N; i++)
  {
    pthread_join(tid[i], NULL);
  }

  printf("Thread-Main: sum = %d\n", sum);
}








void *producer(void *param)
{
  buffer_item rand;
  while(1){
  //generate random $ between 1-3
  sleep(r)    //sleep for random generated number
  }
  int upper = atoi(param);
  //sum = 0;
  for (int i = 0; i <= upper; i++)
  {
    sem_wait(&sem_mutex);
    sum += i;
    sem_post(&sem_mutex);
  }

  pthread_exit(0);
}






void *consumer(void *param)
{

  buffer_item rand;
  while(1){
    //gnerate number between 1-3
    sleep(r) //sleep for random generated number
    printf("producer produced %f\n", rand);
    if(remove_item(&rand))
       //output sleeping condition
    else
       printf("consumer consumed %d \n", rand);
}

  int upper = atoi(param);
  //sum = 0;
  for (int i = 0; i <= upper; i++)
  {
    sem_wait(&sem_mutex);
    sum += i;
    sem_post(&sem_mutex);
  }

  pthread_exit(0);
}









#include <pthread.h>
#include <stdlib.h>  /* required for rand() */
#include "buffer.h"
#include <iostream>


pthread_mutex_t mutex;

void *producer(void *param){
  buffer_item rand;
  while(1){
    /* sleep for a random period of time */
    sleep(...);
    /* generate a random number */
    rand = rand();
    printf("producer produced %f\n", rand);
    if(insert_item(rand)){
      /* report error condition */
    }
  }
}



void *consumer(void *param){
  buffer_item rand;
  while(1){
    /* sleep for a random period of time */
    sleep(...);
    printf("producer produced %f\n", rand);
    if(remove_item(&rand)){
        /* report error condition */
    }else{
      printf("consumer consumed %d \n", rand);
    }
  }
}


int main( int argc, char *argv[] ){
  
  //Get command line arguments
  int simulation_time = argv[1];
  int max_thread_sleeptime = argv[2];
  int num_producer_thread = argv[3];
  int num_consumer_thread = argv[4];

  Initialize buffer
  Create producer thread(s)
  Create consumer thread(s)
  Sleep
  Join Threads
  Display Statistics
  Exit
}

void output(){
  cout << "Producer " << tid << " writes " << rand_value << endl << "(buffers occupied: " << num_buf_occupy << ")\n";
  cout << "buffers:\t";
  for(int i = 0; i < 5; i++){
    cout << *buffer[i] << "\t"
  }
}
  






/* create the mutex lock */
pthread_mutex_init( &mutex, NULL );

/* aquire the mutex lock */
pthread_mutex_lock( &mutex );

/*** CRITICAL SECTION ***/

/* release the mutex lock */ 
pthread_mutex_unlock( &mutex );