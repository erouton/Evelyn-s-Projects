/*****************
 * Evelyn Routon
 * March 1, 2023
 * CSC 131
 * Lab 4 Problem 2
 * Prompt the user to enter a sentence that ends with
 * either . ? or ! count the total number of spaces,
 * newlines, and tabs within the sentence and output.
 * Demonstrates cin.get(char) and switch/case statements.
 * ***************/

#include <iostream>
using namespace std;

int main(){
    char c;
    int spaces = 0, tabs = 0, nlines = 0;
    cout << "Enter a sentence (end by '.' or '?' or '!'): ";
    while (cin.get(c) && c!= '.' && c!= '!' && c!= '?'){
        switch(c){
            case ' ':
                spaces++;
                break;
            case '\n':
                nlines++;
                break;
            case '\t':
                tabs++;
                break;
        }
    }
    cout << "Number of space characters: " << spaces << endl;
    cout << "Number of new line characters: " << nlines << endl;
    cout << "Number of tabs: " << tabs << endl;
}