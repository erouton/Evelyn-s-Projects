#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// Evelyn Routon

int main()
{
	fstream inFile("proverb.txt", ios::in);
	long offset;
	char ch;
	char more;

	do
	{
        long int current = inFile.tellg();
        cout << "The read position is currently at byte " << current << endl;

		cout << "Enter an offset from the current read position: ";
		cin >> offset;
		offset--;

		inFile.seekg(offset, ios::cur);
        inFile.get(ch);


		cout << "The character read is " << ch << endl;
		cout << "If you would like to input another offset enter a Y"
			 << endl;
		cin >> more;

		inFile.clear();

	} while (toupper(more) == 'Y');

	inFile.close();

	return 0;
}