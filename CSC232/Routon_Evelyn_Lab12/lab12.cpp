#include "MyStack.h"
#include "Inventory.h"
#include <iostream>
using namespace std;

int main(){
    int choice, snum, lnum;
    string date;
    MyStack<Inventory> stack;
    Inventory *item = nullptr;
    while(choice != 3){
        cout << "------Inventory Menu--------\n\n";
        cout << "1. Enter a part into the inventory.\n2. Take a part from the inventory.\n3. Quit.\n";
        cout << "Please make a choice (1, 2, or 3): ";
        cin >> choice;
        if(choice > 3 || choice < 1){
            cout << "Invalid selection.\n";
        }else if(choice == 1){
            cout << "You have chosen to add an item to the inventory bin.\n\n\n";
            cout << "Enter the item's serial number: ";
            cin >> snum;
            cout << "Enter the item's manufacture date: ";
            cin >> date;
            cout << "Enter the item's lot number: ";
            cin >> lnum;

            item = new Inventory;
            item->setserialNum(snum);
            item->setmanufactDate(date);
            item->setlotNum(lnum);
            stack.push(*item);
            delete item;

        }else if(choice == 2){
            Inventory temp;
            cout << "You have chosen to remove an item from the inventory bin.\n";
            stack.pop(temp);
            cout << "The part you removed was:  " << temp << endl;
        }else if(choice == 3){
            cout << "You quit. Bye... ";
        }

        cout << "\n\nThe stack contents as below (from top to bottom)\n";
        stack.print();
            
    }
}