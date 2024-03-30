#include <iostream>
#include "SimpleVector.h"
using namespace std;

int main()
{
   const int SIZE = 5;    // Number of elements
   int count;              // Loop counter
   
   // Create a SimpleVector of ints.
   SimpleVector<string> stringTable(SIZE); 
   stringTable[0] = ("Evelyn");
   stringTable[1] = ("Braegan");
   stringTable[2] = ("Hailey");
   stringTable[3] = ("Bella");
   stringTable[4] = ("Magnus");
   cout << "These values are in stringTable:\n";
   for (count = 0; count < SIZE; count++)
      cout << stringTable[count] << " ";
   cout << endl;
   
   stringTable.pop_back();
   cout << "These values are in stringTable after pop_back function:\n";
   for (count = 0; count < stringTable.size(); count++)
      cout << stringTable[count] << " ";
   cout << endl;

   stringTable.push_back("Hailie");
   cout << "These values are in stringTable after push_back function:\n";
   for (count = 0; count < stringTable.size(); count++)
      cout << stringTable[count] << " ";
   cout << endl;
}