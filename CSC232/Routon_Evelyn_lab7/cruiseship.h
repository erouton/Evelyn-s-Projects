#ifndef CRUISESHIP_H
#define CRUISESHIP_H
#include <iostream>
#include "ship.h"
using namespace std;

class CruiseShip : public Ship{
    private:
        int max;
    public:
        CruiseShip() : Ship(){max = 100;}
        CruiseShip(string n, string y, int m) : Ship(n,y){max = m;}
        int getMax();
        void setMax(int);
        void print();
};  

int CruiseShip::getMax(){
    return max;
}

void CruiseShip::setMax(int m){
    max = m;
}

void CruiseShip::print(){
    cout << "Ship Name: " << name << endl;
    cout << "Max # of Passengers: " << max << endl;
}

#endif