#include <iostream>
#include <string>
using namespace std;

struct drink{
        string name;
        float cost;
        int amount;
    };

int main(){
    drink drinks[5];

    drinks[0].name = "Cola";
    drinks[0].cost = .75;
    drinks[0].amount = 20;

    drinks[1].name = "Root Beer";
    drinks[1].cost = .75;
    drinks[1].amount = 20;

    drinks[2].name = "Lemon-Lime";
    drinks[2].cost = .75;
    drinks[2].amount = 20;

    drinks[3].name = "Grape Soda";
    drinks[3].cost = .80;
    drinks[3].amount = 20;

    drinks[4].name = "Cream Soda";
    drinks[4].cost = .80;
    drinks[4].amount = 20;

    while(true){
        string drink_name;
        int tester = 0;
        float money_earned = 0;

        for(int i = 0; i < 5; i++){
            cout << "Drink Name: " << drinks[i].name << endl;
            cout << "Cost: " << drinks[i].cost << endl;
            cout << "Number in Machine: " << drinks[i].amount << endl << endl;
        }
        cout << "Make a drink selection or enter 'quit': ";
        cin >> drink_name;
        if(drink_name == "quit"){
            cout << "Money earned from machine: " << money_earned << endl;
            break;
        }
        for(int i = 0; i < 5; i++){
            if(drink_name == drinks[i].name && drinks[i].amount == 0){
                cout << "Drink sold out, please make new selection.\n";
                break;
            }
            if(drink_name == drinks[i].name){
                tester++;
                float money, change;
                cout << "Insert Money: ";
                cin >> money;
                if(money < drinks[i].cost || money > 1.00 || money < 0){
                    cout << "Invalid amount of money\n";
                    continue;
                }
                
                change = (drinks[i].cost - money);
                money_earned = drinks[i].cost;
                cout << "Change returned: " << abs(change) << endl;
                drinks[i].amount--;

            }

        }
        if(tester == 0){
            cout << "Invalid selection, please try again\n";
            continue;
        }
    }
}