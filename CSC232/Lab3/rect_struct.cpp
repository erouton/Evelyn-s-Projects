#include <iostream>
#include <iomanip>
using namespace std;

//Evelyn Routon

int main(){
    struct Rectangle{
        int length, width;
        float area, perimeter;
    };
    Rectangle box;
    
    cout << "Enter the length of a rectangle: ";
    cin >> box.length;
    cout << "Enter the width of a rectangle: ";
    cin >> box.width;

    box.area = box.length * box.width;
    box.perimeter = (2*box.length) + (2*box.width);

    cout << fixed << showpoint << setprecision(2);
    cout << "The area of the rectangle is " << box.area << endl;
    cout << "The perimeter of the rectangle is " << box.perimeter << endl;
    if(box.length == box.width){
        cout << "The rectangle is a square.\n";
    }
    return 0;
}