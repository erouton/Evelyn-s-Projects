/*****************
 * Evelyn Routon
 * March 28, 2023
 * CSC131
 * Project 5
 * Prompts the user to enter the size of a table (RowxCol) and
 * then prompts user to enter number values for each Row seperated
 * by either a space or a newline. The program returns the count for
 * each number (0-9) listed in the table as well as printing the
 * original table entered by user.
 * This project was useful for teaching and demonstrating various
 * skills with not only 1D arrays but specifically 2D arrays.
 * ***************/

#include <iostream>
using namespace std;

int main(){
    int r, c;
    cout << "This program counts occurrences of digits 0 through 9 in an NxM array.\n";
    cout << "Enter the size of the array (Row Column): ";
    cin >> r >> c;
    int table[r][c];
    int digits[10] = {0};

    for(int i = 0; i < r; i++){
        cout << "Enter all of row " << i << " (seperated either by a space or newline): ";
        for(int j = 0; j < c; j++){
            cin >> table[i][j];
            digits[table[i][j]]++;
        }
    }

    cout << "Total counts for each digit:\n";
    for(int num = 0; num < 10; num++){
        cout << "Digit " << num << " occurs " << digits[num] << " times\n";   
    }

    cout << "The digit counts directly from the 1D array:\n";
    for(int num = 0; num < 10; num++){
        cout << digits[num] << " ";
    }
    
    cout << "\nThe original 2D array entered by the user:\n";
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
}