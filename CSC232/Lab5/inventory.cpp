#include <iostream>
#include <fstream>
using namespace std;

// Evelyn Routon

const int NUMOFPROD = 10;		// This holds the number of products a store sells 

class Inventory
{
public:
	void getId(int item);		// This puts item in the private data member
								// itemNumber of the object that calls it. 

	void getAmount(int num);	// This puts num in the private data member
								// numOfItem of the object that calls it.

	void display();				// This prints to the screen
								// the value of itemNumber and numOfItem of the
								// object that calls it.

private:
	int	itemNumber;				// This is an id number of the product 
	int	numOfItem;				// This is the number of items in stock

};

int main()
{
	ifstream infile;	// Input file to read values into array 
	infile.open("Inventory.dat");

    Inventory products[NUMOFPROD];

	int pos;	// loop counter
	int id;		// variable holding the id number
	int total;	// variable holding the total for each id number


	while(pos < NUMOFPROD){
		infile >> id;
		infile >> total;
		products[pos].getId(id);
		products[pos].getAmount(total);
		pos++;
	}
    
	for(int i = 0; i < NUMOFPROD; i++){
		products[i].display();
	}
	return 0;
}

void Inventory::getId(int item){
	itemNumber = item;
}

void Inventory::getAmount(int num){
	numOfItem = num;
}

void Inventory::display(){
	cout << "Item number " << itemNumber << " has " << numOfItem << " items in stock\n";
}