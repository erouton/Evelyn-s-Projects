#include <iostream>
using namespace std;

template <typename T>
T absolute_val(T num){
    if(num > 0){
        return num;
    }else{
        return (num * -1);
    }}

int main(){
    cout << "The absolute value of 27 is: " << absolute_val(27) << endl;
    cout << "The absolute value of -31 is: " << absolute_val(-31) << endl;
    cout << "The absolute value of 0 is: " << absolute_val(0) << endl;
}