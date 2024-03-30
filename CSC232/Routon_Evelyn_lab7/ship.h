#ifndef SHIP_H
#define SHIP_H
#include <iostream>
using namespace std;

class Ship{
    protected:
        string name;
        string year;
    public:
        Ship() : Ship("Ship","2023"){}
        Ship(string, string);
        string getName();
        string getYear();
        void setName(string);
        void setYear(string);
        virtual void print();
};

Ship::Ship(string n, string y){
    name = n;
    year = y;
}

string Ship::getName(){
    return name;
}

string Ship::getYear(){
    return year;
}

void Ship::setName(string n){
    name = n;
}

void Ship::setYear(string y){
    year = y;
}

void Ship::print(){
    cout << "Ship Name: " << name << "\nShip Year: " << year << endl;
}


#endif
