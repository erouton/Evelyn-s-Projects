// Evelyn Routon

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int NAMESIZE = 15;
const int MAXREC = 20;

struct	budget	// declare a structure to hold name and financial information
{
	char name[NAMESIZE + 1];
	float income;		// person's monthly income 
	float rent;			// person's monthly rent
	float food;			// person's monthly food bill 
	float utilities;	// person's monthly utility bill 
	float miscell;		// person's other bills
	float net;			// person's net money after bills are paid
};

typedef budget recordtype[MAXREC];

int main()
{   
	fstream indata;
	ofstream outdata;	// output file of
						// student. 

	indata.open("income.dat", ios::out | ios::binary);	// open file as binary
														// output.

	outdata.open("student.out");	// output file that we
									// will write student
									// information to. 

	outdata << left << fixed << setprecision(2);	// left indicates left
													// justified for fields 

    recordtype person;
    char check = 'Y';
	int totalrecs = 0;

    while(check == 'y' | check == 'Y'){
        cout << "Enter the following information" << endl;

        cout << "Person's name: ";
        cin.getline(person[totalrecs].name, NAMESIZE);

        cout << "Income :";
        cin >> person[totalrecs].income;

        cout << "Rent: ";
        cin >> person[totalrecs].rent;

        cout << "Food: ";
        cin >> person[totalrecs].food;

        cout << "Utilities: ";
        cin >> person[totalrecs].utilities;

        cout << "Miscellaneous: ";
        cin >> person[totalrecs].miscell;


        // find the net field
        person[totalrecs].net = person[totalrecs].income - (person[totalrecs].rent + person[totalrecs].food + person[totalrecs].utilities + person[totalrecs].miscell);

        indata.write((char *)&person[totalrecs], sizeof(person[totalrecs]));


        totalrecs++;

        cout << "Enter a Y if you would like to input more data\n";
        cin >> check;
        cin.ignore();
    }
    indata.close();
    indata.open("income.dat", ios::in);

    outdata << setw(20) << "Name" << setw(10) << "Income" << setw(10) << "Rent"
                << setw(10) << "Food" << setw(15) << "Utilities" << setw(15)
                << "Miscellaneous" << setw(10) << "Net Money" << endl << endl;

    for(int i = 0; i < totalrecs; i++){
        indata.read((char *)&person[i],sizeof(person[i])); //reads record from file

        outdata << setw(20) << person[i].name << setw(10) << person[i].income << setw(10) << person[i].rent
                << setw(10) << person[i].food << setw(15) << person[i].utilities << setw(15)
                << person[i].miscell << setw(10) << person[i].net << endl << endl;
    }
    
    indata.close();
    outdata.close();
    // FILL IN CODE TO WRITE INDIVIDUAL FIELD INFORMATION OF THE RECORD TO
	// THE outdata FILE.(several instructions)

	return 0;
}