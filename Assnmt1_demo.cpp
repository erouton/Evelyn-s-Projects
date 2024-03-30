/*****************
Might need to remove this from repository
Evelyn Routon

*******************/

#include <iostream>
#include<stdlib.h>
using namespace std;

int Summation(int array[], int x, int mylength){
    int sum = 0 ,i = 0 ,a = 0;
    while(i < mylength){
        int j = 0;
        a = array[i];
        while (j < i){
            a = a * x;
            j = j + 1;  
        }
        sum = sum + a;
        i = i + 1;
    }
    return sum;
}

int Sum3(int array [], int x, int n){
    int result = array[n-1];
    n = n -1;
    while(n>0){
        result = result * x + array[n-1];
        n = n - 1;
    }
    return result;

}

int main(){
    int my_array[4] = {1, 2, 6, 20};
    int num = 3;
    int elements = 4;
    cout << "the result is: " << Summation(my_array, num, elements) << endl;
    cout << "second sum is : " << Sum3(my_array, num, elements) << endl;
    return 0;
}   
