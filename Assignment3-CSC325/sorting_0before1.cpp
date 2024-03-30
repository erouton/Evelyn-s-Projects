/*******************************
 * Assignment 8 - CSC 325-001
 * Problem 1.A
 * Evelyn Routon 
 * March 26, 2024
 * 
 * Write a function that takes an array with values equal
 * to 0 or 1 and the length of the array as parameters, 
 * and sorts the array where all 0's are before every 1.
 * Example: 
 * OG array = {0,1,1,0,0,0,1}
 * SORTED array = {0,0,0,0,1,1,1}
 * 
 * Use your rough pseudocode to write this function,
 * either ensure pseudocode is correct or revise from
 * function implementation. 
 * Use function and corrected pseudocode to state and
 * justify the time complexity of the algorithm.
 * 
 * *****************************/

#include <iostream>
using namespace std;

void Sort_0and1 (int array[], int length);

int main(){
    cout << "Array: 1, 1, 0, 0, 0, 1, 1 \n";
    int a[]={1, 1, 0, 0, 0, 1, 1};
    int len = sizeof(a)/sizeof(0);
    
    Sort_0and1(a, len);
    cout << "Sorted Array: ";
    for(int i = 0; i<len; i++){
        cout << a[i] << " ";
    }cout << endl;
    
}

void Sort_0and1 (int array[], int length){

    int sorted_array[length];
    int x = 0, i = 0, zero = 0, one = length - 1;

    while(i < length){
        if(array[i] == 0){sorted_array[zero++] = 0; }
        else if(array[i] == 1){sorted_array[one--] = 1;    }
        i++;
    }
    while(x < length){array[x] = sorted_array[x]; x++;  }
    return;
}
