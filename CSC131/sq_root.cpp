/**************
 * Evelyn Routon
 * March 8, 2023
 * Project 4
 * Guesses the square root of a user defined number
 * by starting from 1.0, adding the previous guess
 * to the actual number/previous guess, which is then
 * all divided by 2. It does this until it is either
 * the square root of the entered number, or within
 * .00001
 * 'Square Root Guestimator' -- new file name possibility
 * ************/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    float num, guess;
    const float ONE_E_MINUS_5 = 0.00001;
    guess = 1.0;
    cout <<"Enter a number: ";
    cin >> num;

    cout << "\t" << fixed << setprecision(5) << guess << endl;
    while(fabs(pow(guess, 2.0) - num) > ONE_E_MINUS_5){
        guess = (guess + (num / guess)) / 2.0;
        cout << "\t" << fixed << setprecision(5) << guess << endl;
    }
    cout << "Estimated square root of " << fixed << setprecision(5) << num << ": " << guess << endl;
}