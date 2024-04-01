/****************
 * Evelyn Routon
 * February 21, 2023
 * CSC 131
 * Project 3
 * Asks the user to enter information about three book collections.
 * Each collection has 1. a number of volumes and 2. a price per 
 * volume. Asks how many volumes and what is the price per volume 
 * for each collection
 * 
 * Updated March 31, 2024
 * --minor changes made to things like variable names for better
 * readability as well as changing setup in various places so
 * it is better to look at. Also changed some of the cin statements
 * as they were redundant. (had two cin statements one after the other
 * instead of using the same statement seperated by >> for different
 * variables to be read, 
 * example line 33: 
 * cin >> volume1;
 * cin >> price1;
 * changed to:
 * cin >> volume1 >> price1;
 * )
 * **************/

#include <iostream>
using namespace std;

int main(){
    int collection1, collection2, collection3, bob_budget, price1, price2, price3, volume1, volume2, volume3;

    //Prompting user for price/volume for each collection
    cout << "Enter volumes and price per volume for collection 1: ";
    cin >> volume1 >> price1;
    collection1 = volume1 * price1;

    cout << "Enter volumes and price per volume for collection 2: ";
    cin >> volume2 >> price2;
    collection2 = volume2 * price2;

    cout << "Enter volumes and price per volume for collection 3: ";
    cin >> volume3 >> price3;
    collection3 = volume3 * price3;

    cout << "Enter Bob's budget: ";
    cin >> bob_budget;

    //Condition 1 -- checking whether Bob has any money at all in his budget
    if (bob_budget > 0){
        cout << "(1) Bob has some money to buy collections." << endl;   
    }else{
        cout << "(1) Bob does not have money to buy anything." << endl;    
    }

    /*Condition 2 -- checks whether Bob has enough in his budget to buy all
    three collections or not*/
    if (bob_budget >= collection1 + collection2 + collection3){
        cout << "(2) Bob has enough money to buy all three collections." << endl;
    }else{
        cout << "(2) Bob does not have enough money to buy all three collections." << endl;
    }

    /*Condition 3 -- checks if there are at least 2 out of 3 collections that
    are individually more expensive than Bob's budget*/
    if (bob_budget < collection1 && bob_budget < collection2){
        cout << "(3) At least two collections are more expensive than Bob's budget." << endl;
    }else if (bob_budget < collection1 && bob_budget < collection3){
        cout << "(3) At least two collections are more expensive than Bob's budget." << endl;
    }else if (bob_budget < collection2 && bob_budget < collection3){
        cout << "(3) At least two collections are more expensive than Bob's budget." << endl;
    }else{
        cout << "(3) At least two collections are cheaper than or equal to Bob's budget." << endl;
    }

    //Condition 4 -- checks if any 2 collections cost the same amount or not
    if (collection1 == collection2){
        cout << "(4) At least two collections cost the same amount of money." << endl;
    }else if (collection1 == collection3){
        cout << "(4) At least two collections cost the same amount of money." << endl;
    }else if (collection2 == collection3){
        cout << "(4) At least two collections cost the same amount of money." << endl;
    }else{
        cout << "(4) No two collections have the same price." << endl;
    }

    /*Condition 5 -- checks if only one collection is less than Bob's budget or if
    more than one is cheaper/they are all more expensive*/
    if (bob_budget >= collection1 && bob_budget < collection2 && bob_budget < collection3){
        cout << "(5) Only one collection is cheaper than or equal to Bob's budget. " << endl;
    } else if (bob_budget >= collection2 && bob_budget < collection1 && bob_budget < collection3){
        cout << "(5) Only one collection is cheaper than or equal to Bob's budget. " << endl;
    }else if (bob_budget >= collection3 && bob_budget < collection2 && bob_budget < collection1){
        cout << "(5) Only one collection is cheaper than or equal to Bob's budget. " << endl;
    }else{
        cout << "(5) More than one collection is cheaper than or equal to Bob's budget or they are all more expensive." << endl;
    }

    return 0;
} 