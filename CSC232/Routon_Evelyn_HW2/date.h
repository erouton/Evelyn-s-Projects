#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date(): Date(1, 1, 2023){}
        Date(int d, int m, int y){
            int cm = CheckMonth(m);
            int cd = CheckDay(d);
            if(cm == 0 || cd == 0){
                cout << "ERROR, invalid date\n";
            }else if(cm == 1 && cd == 1){
                day = d;
                month = m;
                year = y;}}
        void CalendarDate(){
            cout << month << "/" << day << "/" << year << endl;}
        void AmericanEnglishDate(){
            string m = ConvertMonth(month);
            cout << m << " " << day << "," << year << endl;}
        void BritishEnglishDate(){
            string m = ConvertMonth(month);
            cout << day << " " << m << " " << year << endl;}
        string ConvertMonth(int mon){
            string temp;
            switch(mon){
                case 1: temp = "January"; break;
                case 2: temp = "February"; break;
                case 3: temp = "March"; break;
                case 4: temp = "April"; break;
                case 5: temp = "May"; break;
                case 6: temp = "June"; break;
                case 7: temp = "July"; break;
                case 8: temp = "August"; break;
                case 9: temp = "September"; break;
                case 10: temp = "October"; break;
                case 11: temp = "November"; break;
                case 12: temp = "December"; break;}
            return temp;}
        int CheckMonth(int m){
            int status;
            if(m > 0 && m < 13){
                return status =1;
            }else    
                return status = 0;}
        int CheckDay(int d){
            int status;
            if(d > 0 && d < 32){
                return status = 1;
            }else
                return status = 0;}
        void FixDay(){
            if(CheckDay(day)==1){
                return;
            }else if(day == 32){
                day = 1;
                ++month;
                if(CheckMonth(month)==1){
                    return;
                }else
                    month = 1;
                    ++year;
            }else if(day == 0){
                day = 31;
                --month;
                if(CheckMonth(month)==1){
                    return;
                }else   
                    month = 12;
                    --year;}}
        Date operator++(){
            ++day;
            FixDay();
            return *this;}
        Date operator++(int){
            Date temp(day, month, year);
            day++;
            FixDay();
            return temp;}
        Date operator--(){
            --day;
            FixDay();
            return *this;}
        Date operator--(int){
            Date temp(day, month, year);
            day--;
            FixDay();
            return temp;}
        int operator-(const Date &right){
            int minus1,minus2,minus, daym, tempm;
            daym = (month - 1) * 31;
            tempm = (right.month - 1) * 31;
            minus1 = daym - tempm;
            minus2 = day - right.day;
            minus = minus1 + minus2;
            return minus;}
        friend ostream &operator << (ostream &strm, const Date &obj);
        friend istream &operator >> (istream &, Date &);
};

ostream &operator << (ostream &strm, const Date &obj){
    Date temp = obj;
    string m = temp.ConvertMonth(temp.month);
    strm << m << " " << temp.day << "," << temp.year << endl;
    return strm;
}

istream &operator >> (istream &strm, Date &obj){
    int m, d, y;
    cout << "Day: ";
    strm >> d;
    cout << "Month: ";
    strm >> m;
    cout << "Year: ";
    strm >> y;
    int cm = obj.CheckMonth(m);
    int cd = obj.CheckDay(d);
    if(cm == 0 || cd == 0){
        cout << "ERROR, invalid date\n";
    }else if(cm == 1 && cd == 1){
        obj.day = d;
        obj.month = m;
        obj.year = y;}
    return strm;
}


#endif