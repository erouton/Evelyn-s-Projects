#include <iostream>
#include <iomanip>
using namespace std;

// This program demonstrates how to use an array of structures

// Evelyn Routon

struct taxPayer{
    float taxRate, income, taxes;
};

int main()
{
    taxPayer citizen[5];

	cout << fixed << showpoint << setprecision(2);

	cout << "Please enter the annual income and tax rate for 5 tax payers: ";
	cout << endl << endl << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter this year's income for tax payer " << (i + 1);
		cout << ": ";

        cin >> citizen[i].income;

		cout << "Enter the tax rate for tax payer # " << (i + 1);
		cout << ": ";

		cin >> citizen[i].taxRate;

		citizen[i].taxes = citizen[i].taxRate * citizen[i].income;

		cout << endl;
	}

	cout << "Taxes due for this year: " << endl << endl;

	for(int index = 0; index < 5; index++)
	{
		cout << "Tax Payer # " << (index + 1) << ": " << "$ "
		     << citizen[index].taxes << endl;
	}

	return 0;
}