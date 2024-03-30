#include<iostream>
#include <iomanip>
#include "linkedlist.h"
using namespace std;

int main()
{
   int months=12;  // The number of months
      
   // LinkedList to hold the rainfall data.
   LinkedList<double> rainFall;

   // Get the rainfall for each month.
   for (int month = 0; month < months; month++)
   {
      double rainAmount;

      // Get this month's rainfall.
      cout << "Enter the rainfall (in inches) for month #";
      cout << (month + 1) << ": ";
      cin >> rainAmount;
	        
      // Validate the value entered.
      while (rainAmount < 0)
      {  
         cout << "Rainfall must be 0 or more.\n"
              << "Please re-enter: ";
         cin  >> rainAmount;
      }

	  // Append the rain amount to the list.
	  rainFall.appendNode(rainAmount);
   }
   
   // Set the numeric output formatting.
   cout << fixed << showpoint << setprecision(2) << endl;
   
   // Display the total rainfall.
   cout << "The total rainfall for the period is ";
   cout << rainFall.getTotal() << " inches." << endl;
   
   // Display the average rainfall.
   cout << "The average rainfall for the period is ";
   cout << rainFall.getAverage() << " inches." << endl;

   // Display the largest amount of rainfall.
   cout << "The largest amount of rainfall was ";
   cout << rainFall.getLargest() << " inches in month ";
   cout << (rainFall.getLargestPosition() + 1) 
	    << "." << endl;

   // Display the smallest amount of rainfall.
   cout << "The smallest amount of rainfall was ";
   cout << rainFall.getSmallest() << " inches in month ";
   cout << (rainFall.getSmallestPosition() + 1) 
	    << "." << endl << endl;

   return 0;
}