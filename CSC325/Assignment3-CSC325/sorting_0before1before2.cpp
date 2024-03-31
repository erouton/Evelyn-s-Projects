/*******************************
 * Assignment 8 - CSC 325-001
 * Problem 1.B
 * Evelyn Routon 
 * March 26, 2024
 * 
 * Write a function that takes an array with values equal
 * to 0, 1, or 2 and the length of the array as parameters, 
 * and sorts the array where all 0's are before every 1 and
 * all 1's are before every 2.
 * Example: 
 * OG array = {2,0,1,2,1,0,2,0,0,1,2,0,2}
 * SORTED array = {0,0,0,0,0,1,1,1,2,2,2,2,2}
 * 
 * Use your previous function for sorting 0 before 1 to 
 * write this function revise pseudocode from this
 * function implementation. 
 * Use function and corrected pseudocode to state and
 * justify the time complexity of the algorithm, as well
 * as providing a proof of correctness using the loop-invariant
 * method.
 * 
 * Used as reference:
 * https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/
 * --realized my 1st way was not going to working for a number of reasons
 * 1. were are creating 3 arrays, which is inefficient
 * 2. in order to merge all 3 arrays @ end, you have to check
 *    if array[i] is null or not, since the array won't be 
 *    entirely filled
 * 3. cannot use just 2 arrays either, because you would have
 *    empty space in the middle of the array
 * *****************************/

#include <iostream>
#include <array>
#include <stdlib.h>
using namespace std;

void Sort_0_1_2 (int array[], int length);

int main(){
    cout << "Array: 0, 2, 0, 1, 2, 2, 1, 2, 0, 2, 1, 0, 1\n";
    int a[]={0,2, 0,1, 2, 2, 1,2, 0,2, 1,0,1};
    Sort_0_1_2(a, 13);
    cout << "Sorted Array: ";
    for(int i = 0; i<13; i++){
        cout << a[i] << ", ";
    }cout << endl;
    
}

void Sort_0_1_2 (int array[], int length){

    int zero = 0, two = 0, one = 0;
    for(int i = 0; i < length; i++){
        if(array[i] == 0){zero++;   }
        else if(array[i] == 1){one++;  }
        else if(array[i] == 2){two++;  }
    }

    int l = 0;
    for(int i = 0; i < zero && l < length; i++, l++){array[l] = 0;  }
    for(int i = 0; i < one && l < length; i++, l++){array[l] = 1;  }
    for(int i = 0; i < two && l < length; i++, l++){array[l] = 2;  }
    
    return;
}
