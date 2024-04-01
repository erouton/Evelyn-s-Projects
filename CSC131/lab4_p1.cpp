/****************
 * Evelyn Routon
 * March 1, 2023
 * CSC131
 * Lab 4 - Problem 1
 * Output a list of drinks (coffee, tea, coke, orange juice) and
 * prompt the user to input the drink of person # __ or to exit.
 * Afterwards, output the the total # of people, as well as the
 * count for each beverage.
 * This project problem is to help learn and demonstrate 
 * switch/case statements.
 * *************/

#include <iostream>
using namespace std;

int main(){
    int bev = 0;
    int coffee = 0;
    int tea = 0;
    int coke = 0;
    int juice = 0;
    int person = 1;
    cout << "1.  Coffee       2. Tea      3. Coke       4. Orange Juice\n";
    while (bev != -1){
        cout << "Please input the favorite beverage of person #" << person << ": Choose 1, 2, 3, or 4 from the above menu or -1 to exit program ";
        cin >> bev;
        switch (bev){
            case 1: coffee++;
                    break;
            case 2: tea++;
                    break;
            case 3: coke++;
                    break;
            case 4: juice++;
                    break;
    }   person++;
    }
    cout << "The total number of people surveyed is " << (person - 1) << ". The results are as follows:" << endl;
    cout << "Beverage \t \t Number of Votes \n";
    cout << "************************************** \n";
    cout << "\t Coffee \t\t" << coffee << "\n\t Tea \t\t\t" << tea << "\n\t Coke \t\t\t" << coke << "\n\t Orange Juice \t\t" << juice << endl;
}