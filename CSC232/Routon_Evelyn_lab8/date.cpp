#include <iostream>
#include <string>
#include "stdlib.h"
using namespace std;

const int NUM_MONTHS = 12;

class Date
{
private:
   int month;  // To hold the month
   int day;    // To hold the day
   int year;   // To hold the year
   string names[NUM_MONTHS];
   void setNames();
public:
   Date();
   Date(int, int, int);
   void setMonth(int m);
   void setDay(int d);
   void setYear(int y);
   void showDate1();
   void showDate2();
   void showDate3();
   class InvalidDay {};
   class InvalidMonth {};
};

Date::Date(){
   setNames();
}

Date::Date(int m, int d, int y){
   setMonth(m);
   setDay(d);
   setYear(y);
   setNames();
}

void Date::setNames(){
   names[0] = "January";
   names[1] = "Febraury";
   names[2] = "March";
   names[3] = "April";
   names[4] = "May";
   names[5] = "June";
   names[6] = "July";
   names[7] = "August";
   names[8] = "September";
   names[9] = "October";
   names[10] = "November";
   names[11] = "December";
}

void Date::setMonth(int m){
   if (m >= 1 && m <= 12)
      month = m;
   else{
      throw InvalidMonth();
   }}

void Date::setDay(int d){
   if (d >= 1 && d <= 31)
         day = d;
   else{
      throw InvalidDay();
   }}

void Date::setYear(int y){
   year = y;
}

void Date::showDate1(){
   cout << month << "/"
        << day << "/"
        << year << endl;
}

void Date::showDate2(){
   cout << names[month-1]
        << " " << day << ", "
        << year << endl;
}

void Date::showDate3(){
   cout << day << " "
        << names[month-1]
        << " " << year << endl;
}

int main(){
   // Create a Date object and initialize it
   // using the overloaded constructor.
   Date today;
   int month, day, year;
   cout << "Enter today's month: ";
   cin >> month;
   cout << "Enter today's day: ";
   cin >> day;
   cout << "Enter today's year: ";
   cin >> year;
   try{
        today.setMonth(month);
        today.setDay(day);
        today.setYear(year);
        today.showDate1();
        today.showDate2();
        today.showDate3();
   }catch(Date::InvalidDay){
        cout << "Error: Invalid value for day entered.\n";
   }catch(Date::InvalidMonth){
        cout << "Error: Invalid value for month entered.\n";
   }

   return 0;
}