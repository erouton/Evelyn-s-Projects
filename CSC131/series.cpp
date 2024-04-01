/***********
 * Evelyn Routon
 * March 8, 2023
 * CSC131
 * Project 4
 * Calculate a series from number entered by user where 
 * it does the following for and EVEN number x:
 * (-1*1^2) + (1*2^2) + (-1*3^2) + (1*4^2) + ... + (1*n^2)
 * 
 * and the following for and ODD number y:
 * (-1*1^2) + (1*2^2) + (-1*3^2) + (1*4^2) + ... + (-1*n^2)
 * ********/

#include <iostream>
using namespace std;

int main(){
    int n, num, one;
    int s = 0;
    cout << "Enter an integer number: ";
    cin >> n;
    for(num = 1; num <= n; num++){
        if (num % 2 == 0){
            one = -1;
        }else{
            one = 1;
        }
        s += ((one) * (num*num));
        
    }
    
    cout << "The value of the series is: " << s << endl;
}