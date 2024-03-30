#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include <iostream>
#include "ship.h"
using namespace std;

class CargoShip : public Ship{
    private:
        int cargo;
    public:
        CargoShip() : Ship(){cargo = 1000;}
        CargoShip(string n, string y, int c) : Ship(n,y){cargo = c;}
        void setCargo(int);
        int getCargo();
        void print();
};

void CargoShip::setCargo(int c){
    cargo = c;
}

int CargoShip::getCargo(){
    return cargo;
}

void CargoShip::print(){
    cout << "Ship Name: " << name << endl;
    cout << "Cargo Capacity: " << cargo << endl;
}

#endif