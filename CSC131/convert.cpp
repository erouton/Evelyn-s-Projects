/*************
 * Evelyn Routon
 * February 15, 2023
 * CSC131
 * Project 2 - Problem 1
 * Write a program that reads an integer entered by the user and displays it in binary
 * 'Binary Converter' -- new file name possibility
 * ***********/
#include <iostream>
using namespace std;

int main()
{
    int num, binary, b0, b1, b2, b3, b4;
    cout << "Enter a number between 0 and 31: ";
    cin >> num;
    b0 = num % 2;
    b1 = (num / 2) % 2;
    b2 = (num / 4) % 2;
    b3 = (num / 8) % 2;
    b4 = (num / 16) % 2;
    cout << "In binary, your number is: " << b4 << b3 << b2 << b1 << b0 << endl;
    return 0;
}