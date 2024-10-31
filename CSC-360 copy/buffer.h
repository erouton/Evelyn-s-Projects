
//********************************************************************
//
// Evelyn Routon
// Operating Systems
// Project #3: Process Synchronization Using Pthreads: The Producer / Consumer Problem With Prime Number Detector
// October 9, 2024
// Instructor: Dr. Siming Liu
//
//********************************************************************
#ifndef _BUFFER_H_DEFINED_
#define _BUFFER_H_DEFINED_
#include <iostream>
#include <iomanip>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

typedef int buffer_item;

#define BUFFER_SIZE 5
buffer_item global_buffer[BUFFER_SIZE];
unsigned int bufferCount=0; 
unsigned int buffer_In_index=0; 
unsigned int buffer_Out_index=0; 

bool buffer_insert_item( buffer_item item );
bool buffer_remove_item( buffer_item *item );
void buffer_print();
void buffer_initialize();

sem_t bufferEmpty;
sem_t bufferFull;
pthread_mutex_t mutex;

/********************************************************************
//
// Buffer Initialize
//
// This function initializes the semaphores, mutexs and buffer positions to -1
//
// Return Value
// ------------
// void
//
*******************************************************************/
void buffer_initialize(){
   sem_init(&bufferEmpty, 0, BUFFER_SIZE );
   sem_init( &bufferFull, 0, 0 );
   pthread_mutex_init( &mutex, NULL );
   for(int i=0 ; i < BUFFER_SIZE; i++){
       global_buffer[i] = -1; 
   }
}

/********************************************************************
//
// Buffer Insert Item Function
//
// This function inserts an item into the buffer moves the buffer index and adds one to the count of the buffer
//
// Return Value
// ------------
// bool                         True that function succeeded
//
// Value Parameters
// ----------------
// item       buffer_item   Value to place into buffer
//
*******************************************************************/
bool buffer_insert_item( buffer_item item ){
   cout << "Item: " << (int) item << endl; 
   global_buffer[buffer_In_index] = item;

   //move buffer in index plus one in circular fashion
   buffer_In_index = (buffer_In_index + 1) % BUFFER_SIZE;

   bufferCount++;
   return true;
}

/********************************************************************
//
// Buffer Remove Item Function
//
// This function removes an item from the buffer, moves the buffer index, and subtracts one from the count of the buffer
//
// Return Value
// ------------
// bool                         True that function succeeded
//
// Reference Parameters
// ----------------
// item       buffer_item   Value to remove from buffer
//
*******************************************************************/
bool buffer_remove_item( buffer_item *item ){
   *item = global_buffer[buffer_Out_index];

   //Move out to next index position in circular fashion
   buffer_Out_index = ( buffer_Out_index + 1) % BUFFER_SIZE;

   bufferCount--;
   return true;
}



/********************************************************************
//
// Linear Search Function
//
// This function prints out the number of buffers occupied by the buffers contents. It also prints the position of the in and out indexes.
//
// Return Value
// ------------
// void
//
*******************************************************************/
void buffer_print(){
   cout << "(buffers occupied: " << (uint) bufferCount << ")\n";
   cout << "buffers: ";
     
   for(int i=0; i < BUFFER_SIZE; i++)
       cout << " " << (uint) global_buffer[i] << " ";
   cout << endl; 

   cout << "        ";
   for(int i=0; i < BUFFER_SIZE; i++)
       cout << " ----";
   cout << endl;
   cout << "         ";
   for(int i=0; i < BUFFER_SIZE; i++){
       cout << " ";
       if(buffer_In_index == i || buffer_Out_index == i){
           if( bufferCount == BUFFER_SIZE )
               cout << "WR";
           else if( bufferCount == 0 )
               cout << "RW";
           else if( buffer_In_index == i )
               cout << "W ";
           else
               cout << "R ";
           cout << " ";
       }else
           cout << "    ";
   }cout << endl << endl;

}
#endif // _BUFFER_H_DEFINED_