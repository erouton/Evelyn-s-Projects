//********************************************************************
//
// Evelyn Routon
// Operating Systems
// Project #3: Process Synchronization Using Pthreads: The Producer / Consumer Problem With Prime Number Detector
// October 9, 2024
// Instructor: Dr. Siming Liu
//
//********************************************************************
#ifndef STATS_H
#define STATS_H
#include <iostream>
using namespace std;

class Stats{
   private:
       int simulation_time; 
       int max_thread_sleep_timeTime; 
       int p_num; 
       int c_num;
       int buffer_size; 
       int total_consumed;
       int total_produced;

   public:
       //vars
       int *total_thread_produced; //holds # of items produced in array for each thread
       int *total_thread_consumed; //holds # of items consumed in array for each thread
       int amount_buffer_full; //total # of times the buffer was full
       int amount_buffer_empty; //total # of times the buffer was empty
       int num_remaining; //total # of items that were left in the buffer


       void print(); 
       Stats(int, int, int, int, int); 
       ~Stats();
};


/*********************************************************
//
// Stats Constructor Function
//
// This function initializes all of the values passed in by the command line arguments
//
// Return Value
// ------------
// none
//
// Value Parameters
// ----------------
// _simTime        int    simulation time
// _maxSleep        int    maximum sleep time
// _p_num    int    number of producer threads
// _c_num    int    number of consumer threads
// _bufferSize        int    size of buffer
//
*******************************************************************/
Stats::Stats(int _simTime, int _maxSleep, int _p_num, int _c_num, int _bufferSize){
   simulation_time = _simTime;
   max_thread_sleep_timeTime = _maxSleep;
   p_num = _p_num;
   c_num = _c_num;
   buffer_size = _bufferSize;

   //Allocate memory
   total_thread_produced = new int[_p_num];
   total_thread_consumed = new int[_c_num];
}



/********************************************************************
//
// ~Stats Function
//
// This function deletes pointers
//
// Return Value
// ------------
// none
//
*******************************************************************/
Stats::~Stats(){
   delete [] total_thread_produced;
   delete [] total_thread_consumed;
}



/********************************************************************
//
// Print Function
//
// This function prints out a summary of stats at the end of the program
//
// Return Value
// ------------
// void
//
*******************************************************************/
void Stats::print(){

   cout << "PRODUCER / CONSUMER SIMULATION COMPLETE\n";
   cout << "=======================================\n";
   cout << "Simulation Time:" << setw (24) << simulation_time << endl;
   cout << "Maximum Thread Sleep Time:" << setw(16) << max_thread_sleep_timeTime << endl;
   cout << "Number of Producer Threads:" << setw(16) << p_num << endl;
   cout << "Number of Consumer Threads:" << setw(16) << c_num << endl;
   cout << "Size of Buffer:" << setw(24) << buffer_size << "\n\n";
  
   //Producer threads
   int totalProd = 0;

   for(int i=0; i < p_num; i++)
       totalProd += total_thread_produced[i];

   cout << "Total Number of Items Produced:" << setw(11) << totalProd << endl;

   for(int i=0; i < p_num; i++){
       cout << "   Thread " << setw(2);
       cout << (i+1) << ":" << setw(30);
       cout << total_thread_produced[i] << endl;
   }cout << endl;

   int totalCons = 0;

   for(int i=0; i < c_num; i++)
       totalCons += total_thread_consumed[i];

cout << "Total Number of Items Consumed:" << setw(11) << totalCons << endl;

   for(int i=0; i < c_num; i++){
        cout << "   Thread " << setw(2);
        cout << (i+p_num+1) << ":" << setw(30);
        cout << total_thread_consumed[i] << endl;
   }cout << endl;
   cout << "Number Of Items Remaining in Buffer:" << setw(6) << num_remaining << endl;
   cout << "Number Of Times Buffer Was Full:" << setw(10) << amount_buffer_full << endl;
   cout << "Number Of Times Buffer Was Empty:" << setw(9) << amount_buffer_empty << endl;

}

#endif