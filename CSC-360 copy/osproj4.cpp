//********************************************************************
//
// Evelyn Routon
// Operating Systems
// Project #3: Process Synchronization Using Pthreads: The Producer / Consumer Problem With Prime Number Detector
// October 9, 2024
// Instructor: Dr. Siming Liu
//
//********************************************************************
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "buffer.h"
#include "stats.h"
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
using namespace std;

//struct to hold args from command line
struct ARGS{
   int simulation_time; //simulation length
   int max_thread_sleep_time; //maximum sleep time for thread
   int p_num; //number of producers
   int c_num; //number of consumers
   bool output_buffer; //true/false output buffer snapeshots
};

//Global args
ARGS global_args; //create an instance of arguments struct
bool running = true; //flag to indicate that the simluation should stop when false

//function prototype
void arguments(int, char **);
bool checkPrime(buffer_item);
void *producer(void * param);
void *consumer(void * param);

int main(int argc, char *argv[]){
   arguments(argc, argv);
  
   //Store simulation statistics
   Stats simulationStats(global_args.simulation_time, global_args.max_thread_sleep_time, global_args.p_num, global_args.c_num,BUFFER_SIZE);

   buffer_initialize();

   //========= Threads =========
    pthread_t tidP[global_args.p_num]; //producer thread identifier array
    pthread_t tidC[global_args.c_num]; //consumer thread identifier array
    pthread_attr_t attr; //set of thread attributes
    pthread_attr_init( &attr ); //get the default attributes
  
   cout << "Starting Threads...\n";
  
   //Create producer thread(s)
   for(int i=0; i < global_args.p_num; i++){
       pthread_create( &tidP[i], &attr, producer, NULL);
   }

   //Create consumer thread(s)
   for(int i=0; i < global_args.c_num; i++){
       pthread_create( &tidC[i], &attr, consumer, NULL);
   }
  
   sleep(global_args.simulation_time);

   //Signal Threads to quit
   running = false;

   //Used to accept array from threads
   int *tempStats;

   //Join Threads
   for(int i=0; i < global_args.p_num; i++){
       tempStats = (int*) pthread_join( tidP[i], NULL );

       simulationStats.total_thread_produced[i] = tempStats[0];
       simulationStats.amount_buffer_full += tempStats[1];
    }

   for(int i=0; i < global_args.c_num; i++){
       tempStats = (int*) pthread_join( tidC[i], NULL );

       simulationStats.total_thread_consumed[i] = tempStats[0];
       simulationStats.amount_buffer_empty += tempStats[1];
   }
  
   //Grab number of items remaining in buffer
   simulationStats.num_remaining = bufferCount;

   //Display Statistics
   simulationStats.print();

   return 0;
}




/********************************************************************
//
// Arguments function
//
// This function takes in the command line arguments and places them into a struct.
//
// Return Value
// ------------
// void
//
// Value Parameters
// ----------------
// argc       int       Number of arguments in argv
//
// Reference Parameters
// --------------------
// argv    char        Array of char arrays. Provides command line args
//
*******************************************************************/

void arguments(int argc, char *argv[]){
   if(argc < 6){
       cerr << "5 arguments are needed. The arguments should be ";
       cerr << "in the following order:\n simulation length\n ";
       cerr << "max thread sleep\n number of producers\n number ";
       cerr << "of consumers\n yes or no for outputting buffer snapshots\n";
       exit(-1);
   }

   global_args.simulation_time = atoi(argv[1]);
   global_args.max_thread_sleep_time = atoi(argv[2]);
   global_args.p_num = atoi(argv[3]);
   global_args.c_num = atoi(argv[4]);
  
   if(strcmp(argv[5],"yes") == 0){
       global_args.output_buffer = 1;
   }else if(strcmp(argv[5],"no") == 0){
       global_args.output_buffer = 0;
   }else{
       cerr << "The last argument must be 'yes' or 'no'\n";
       exit(-1);
   }

}




/********************************************************************
//
// Check Prime Function
//
// This function determines if a number is prime
//
// Return Value
// ------------
// bool                         True/False if numer is prime
//
// Value Parameters
// ----------------
// in        buffer_item   The value
//
// Local Variables
// ---------------
// lim       int       Limit to go to checking for a prime number
// result   int       Temporary result of mod operation
//
*******************************************************************/
bool checkPrime(buffer_item in){
   int lim = in/2;
   int result;

   for(int i=2; i<=lim; i++){
       result = in % i;
       if(result == 0){
           return false;
       }
   }
   return true;

}




/********************************************************************
//
// Producer function
//
// Producer function to produce numbers and put them into the buffer
//
// Return Value
// ------------
// void
//
// Reference Parameters
// --------------------
// void
// thread returns stats value
//
// Local Variables
// ---------------
// stats    int        holds stats for # of times buffer is full
//                 & number of items produced.
//
*******************************************************************/
void *producer(void * param){
   int * stats = new int[2]; //used to return stats
   int time; //holds random number for time to sleep
   stats[0] = 0; //holds # of items produced
   stats[1] = 0; //holds # of times buffer is full
   buffer_item bItem; 

   while(running)

    while(running){
       //Sleep for a random amount of time.
       time = rand();
       time = time % global_args.max_thread_sleep_time;

       sleep(time);

       //Generate a random number
       bItem = random();
       bItem %= 9999;

       //Check to see if buffer is full
       if(bufferCount == BUFFER_SIZE){
           cout << "All buffers full. Producer " << pthread_self();
           cout << " waits.\n\n";
           stats[1]=(stats[1] + 1);
       }

       //Wait
       sem_wait( &bufferEmpty );

       //Lock
       pthread_mutex_lock( &mutex );

       //Produce - CRITICAL SECTION
       if(running && buffer_insert_item(bItem)){
           cout << "Producer " << pthread_self() << " writes ";
           cout << bItem << endl;

           stats[0]= (stats[0] + 1); //add # of items produced

           if(global_args.output_buffer) //if snapshots enabled
               buffer_print(); //print snapshots
       }

       //unlock
       pthread_mutex_unlock( &mutex );

       //signal
       sem_post( &bufferEmpty );

   }

   pthread_exit( (void*)stats ); //return stats array
}  




/********************************************************************
//
// Consumer function
//
// Consumer function to consume numbers and remove them from the buffer
//
// Return Value
// ------------
// void
//
// Reference Parameters
// --------------------
// void
// thread returns stats value
//
// Local Variables
// ---------------
// stats    int        holds stats for # of times buffer is empty
//                 & number of items consumed.
//
*******************************************************************/
void *consumer(void * param){
   buffer_item bItem; //bItem to store received item
   int time; //int to hold random time to sleep
   int * stats = new int[2]; //array explain on next two lines
   stats[0] = 0; //holds # of items consumed
   stats[1] =0; //holds # of times buffer was empty

   while(running){
       //Sleep for a random amount of time
       time = rand();
       time = time % global_args.max_thread_sleep_time;
       sleep(time);

       //Check if buffers are empty
       if(bufferCount == 0){
           cout << "All buffers empty. Consumer ";
           cout << pthread_self();
           cout << " waits.\n\n";

           stats[1]= (stats[1] + 1); //add one time buffer was empty
       }

       //Check semaphore
       sem_wait( &bufferFull );

       //Lock
       pthread_mutex_lock( &mutex );

       //Consume
       if(running && buffer_remove_item( &bItem)){
           //line 1
           cout << "Consumer " << pthread_self() << " reads ";
           cout << bItem;

           stats[0] = (stats[0]+1); //increase # of items consumed

           if(checkPrime(bItem)) //find if # was prime
               cout << "   * * * PRIME * * *";
           cout << endl;

           //if snapshots are enabled
           if(global_args.output_buffer)
               buffer_print();
       }

       //Unlock
       pthread_mutex_unlock( &mutex );

       //Signal
       sem_post( &bufferFull );

   }

   pthread_exit( (void*)stats ); //return stats for this thread

}







