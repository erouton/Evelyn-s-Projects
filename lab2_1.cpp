#include <iostream>
using namespace std;

bool strictlyEqual(const int[], const int[], int);

int main(){
    int size1, size2, maxsize = 10;

    cout << "Enter list1:";
    cin >> size1;
    int list1[size1];
    for(int i = 0; i < size1; i++){
        cin >> list1[i];
    }
    cout << "Enter list2:";
    cin >> size2;
    int list2[size2];
    for(int i = 0; i < size2; i++){
        cin >> list2[i];
    }
    if(size1 != size2){
        cout << "Two lists are not strictly identical\n";
    }else if(0 == strictlyEqual(list1, list2, size1)){
        cout << "Two lists are not strictly identical\n";
    }else if(1 == strictlyEqual(list1, list2, size1)){
        cout << "Two lists are strictly identical\n";
    }
    return 0;
}

bool strictlyEqual(const int list1[], const int list2[], int size){
    for(int i = 0; i < size; i++){
        if(list1[i] != list2[i]) 
            return false;
        else 
            continue;
}
return true;}