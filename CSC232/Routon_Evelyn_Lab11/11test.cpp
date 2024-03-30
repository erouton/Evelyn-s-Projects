#include<iostream>
#include <iomanip>
#include "linkedlist.h"
using namespace std;

int main()
{
   int months=12;  // The number of months
      
   // LinkedList to hold the rainfall data.
   LinkedList<double> rainfall;

   rainfall.appendNode(6.2);
   rainfall.appendNode(12.3);
   rainfall.appendNode(5.6);
   rainfall.appendNode(10.3);

   rainfall.insertNode(7.3);
   rainfall.insertNode(14.3);


   rainfall.print();


   cout << "Total rainfall: " << rainfall.getTotal() << endl;
   cout << "Number of Nodes: " << rainfall.numNodes() << endl;
   cout << "Average: " << rainfall.getAverage() << endl;
   cout << "Largest Value: " << rainfall.getLargest() << " at position: " << (rainfall.getLargestPosition()+1) << endl;
   cout << "smallest Value: " << rainfall.getSmallest() << " at position: " << (rainfall.getSmallestPosition()+1) << endl;

   cout << "Search 10.3: " << rainfall.search(10.3) << endl;
   cout << "Search 50: " << rainfall.search(50) << endl;

   
   rainfall.removeByPos(0);
   cout << "Removing 1st element: " <<endl;
   rainfall.print();

   rainfall.removeByPos(4);
   cout << "Removing 5th element: " << endl;
   rainfall.print();

   rainfall.removeByPos(10);
   cout << "Trying to Remove Out of Bounds (11th element): " << endl;
   rainfall.print();


}