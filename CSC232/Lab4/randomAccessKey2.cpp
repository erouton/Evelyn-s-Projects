#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// Evelyn Routon

int main()
{
	fstream inFile("proverb.txt", ios::in);
    inFile.seekg(0L, ios::end);
	long int end = inFile.tellg();
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
		long int current2 = inFile.tellg();
		if(current2 > end){
			long new_off = offset - (end - current);
			inFile.clear();
			inFile.seekg(new_off, ios::beg);
		}if(current2 < 0){
			long new_off = offset + current;
			inFile.clear();
			inFile.seekg(new_off, ios::end);
		}
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