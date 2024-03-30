#include "ship.h"
#include "cruiseship.h"
#include "cargoship.h"
#include <iostream>
using namespace std;

int main(){
    Ship *ships[3] = {new Ship("Billings" , "2019"), 
                      new CruiseShip("Aurora", "2000", 1878), 
                      new CargoShip("Armonia", "1924", 2740)};
    for(int i = 0; i < 3; i++){
        cout << "Ship # " << (i+1) << ":\n";
        ships[i]->print();
        cout << endl;
    }
}