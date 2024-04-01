/*************
 * Evelyn Routon
 * February 15, 2023
 * CSC131
 * Project 2 - Problem 2
 * Modify your previous program so that your program reads an integer and a base entered by the user
 * 'Base Converter' -- new file name possibility
 * ***********/
#include <iostream>
using namespace std;

int main()
{
    int num, binary, b0, b1, b2, b3, b4, b;
    cout << "Enter a number between 0 and 31: ";
    cin >> num;
    cout << "Enter a base between 2 and 9: ";
    cin >> b;
    b0 = num % (b);
    b1 = (num / (b)) % (b);
    b2 = (num / (b*b)) % (b);
    b3 = (num / (b*b*b)) % (b);
    b4 = (num / (b*b*b*b)) % (b);
    cout << "In base " << b << ", your number is: " << b4 << b3 << b2 << b1 << b0 << endl;
    return 0;
}