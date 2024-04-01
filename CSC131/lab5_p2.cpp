/***********
 * Evelyn Routon
 * March 8,2023
 * Lab 5 - Problem 2
 * CSC131
 * prompts user to enter an age from 1-100 and keeps count
 * in an array. then outputs all values that have a count
 * (non-zero) 
 * *********/

#include <iostream>
using namespace std;

int main(){
    int n = 100;
    int age[n];
    for(int i = 0; i < 100; i++){
        age[i] = 0;
    }
    while(n!= -99 && n <= 100){
        cout << "Please input an age from one to 100, put -99 to stop\n";
        cin >> n;
        age[n-1]++;
    }for(n = 0; n < 100; n++){
        if (age[n]!=0){
        cout << "The number of people " << n+1 << " years old is " << age[n] << endl;    }
    }
}