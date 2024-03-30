#include <iostream>
using namespace std;

void partition(int[], int);

int main(){
    int size, pivot;
    cout << "Enter list: ";
    cin >> size;
    int list[size], newlist[size];
    for(int i = 0; i<size; i++){
        cin >> list[i];
    }
    partition(list, size);
}

void partition(int list[], int size){
    int pivot = list[0];
    int l = 0, g = 0;
    int lessthan[size], greaterthan[size], newlist[size];
    for(int i = 1; i < size; i++){
        if(list[i]>pivot){
            greaterthan[g] = list[i];
            g++;
        }else if(list[i]<=pivot){
            lessthan[l] = list[i];
            l++;
        }
    }
    for(int i = 0; i < l; i++){
        newlist[i] = lessthan[i];
    }

    newlist[l]=pivot;

    l++;
    for(int i = 0; i < g; i++){
        newlist[l] = greaterthan[i];
        l++;
    }
    for(int i = 0; i < size; i++){
        cout << newlist[i] << " ";
    }
    cout << endl;
}