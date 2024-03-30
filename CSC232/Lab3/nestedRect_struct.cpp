#include <iostream>
#include <iomanip>
using namespace std;

// This program uses a structure to hold data about a rectangle
// It calculates the area and perimeter of a box

// Evelyn Routon

struct dimensions{
    float length, width;
};

struct x{
    float area, perimeter;
};

struct rectangle{
    x attributes;
    dimensions sizes;
};

int main()
{
    rectangle box;

	cout << "Enter the length of a rectangle: ";
    cin >> box.sizes.length;

	cout << "Enter the width of a rectangle: ";
    cin >> box.sizes.width;


	box.attributes.area = box.sizes.width * box.sizes.length;

	box.attributes.perimeter = (2*box.sizes.width) + (2*box.sizes.length);

	cout << fixed << showpoint << setprecision(2);

	cout << "The area of the rectangle is " << box.attributes.area << endl;

	cout << "The perimeter of the rectangle is " << box.attributes.perimeter
		 << endl;

	return 0;
}