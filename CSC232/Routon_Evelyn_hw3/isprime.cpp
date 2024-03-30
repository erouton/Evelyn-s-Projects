#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int user_num=0;
    vector<int> nums;
    while(user_num <= 1){
        cout << "Enter an integer greater than 1: ";
        cin >> user_num;
        if(user_num < 1){
            cout << "Incorrect integer value entered." << endl;
        }else if(user_num > 1){
            for(int i = 2; i<=user_num; i++){
                nums.emplace_back(i);
            }
            auto isprime = [](int p){int divisors = 0; 
                for(int i = 2; i <= p; i++)
                    {if(p%i == 0) {divisors++;}} 
                if(divisors <= 1)
                {cout << p << " is a prime number.\n";}
            };
            for_each(nums.begin(), nums.end(), isprime);
        }
    }
}