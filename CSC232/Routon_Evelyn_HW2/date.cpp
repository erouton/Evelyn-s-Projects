#include <iostream>
#include "date.h"
using namespace std;

int main(){
    Date d1, d2(13,10,2023), d3(18,10,2023);
    cout << "Our starting date is: " << d1 << endl;
    --d1;
    cout << "Decremented is: " << d1 << endl;
    ++d1;
    cout << "Incremented is: " << d1 << endl;
    cout << "Please input a new day.\n";
    cin >> d1;
    cout << "The new date can be written as..." << endl;
    d1.BritishEnglishDate();
    d1.AmericanEnglishDate();
    d1.CalendarDate();

    int minus = d3 - d2;
    cout << "Today's date subtracted from the due date of this assignment is: " << minus << endl;

    cout << "Postfix d1--: " << d1--;
    cout << d1 << endl;
    cout << "Postfix d1++: " << d1++;
    cout << d1 << endl;
}