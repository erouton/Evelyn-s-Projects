#include <iostream>
#include "temperature.h"

using namespace std;
int main(){
    Temperature t(32,'C');
    Temperature x(5, 'C');
    cout<< "Get Degree: " << t.getDegree() << endl;
    cout << "Get Scale: " << t.getScale() << endl;
    cout << "Overloaded subtraction operator: " << (t - x) << endl;
    cout << "t < x: " << (t < x) << endl;
    cout << "t > x: " << (t > x) << endl;
    cout << "t == x: " << (t==x) << endl;
    cout << "t != x: " << (t!=x) << endl;
    cout << "Temperature Converter(C>K): " << t.tempConverter(t, 'K') << endl;
    cout << "Temperature Converter(K>C): " << t.tempConverter(t, 'C') << endl;
    cout << t;
    cin >> t;
    cout<< "Get Degree: " << t.getDegree() << endl;
    cout << "Get Scale: " << t.getScale() << endl;
    
    return 0;
}