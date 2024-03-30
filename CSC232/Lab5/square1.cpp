// This program declares the Square class and uses member functions to find
// the perimeter and area of the square

// Evelyn Routon

#include <iostream>
using namespace std;

class Square{
    public:
        void setSide(float);
        float findArea();
        float findPerimeter();  
        float side;   
};

int main()
{
	Square box;	// box is defined as an object of the Square class
	float size;	// size contains the length of a side of the square

    cout << "Please input the length of the side of the square ";
    cin >> size;
    box.side = size;

    box.setSide(size);

    cout << "The area of the square is " << box.findArea() << endl;

    cout << "The perimeter of the square is " << box.findPerimeter() <<endl;

	return 0;
}


void Square::setSide(float length)
{
	side = length;
}


float Square::findArea()
{
	return side * side;
}


float Square::findPerimeter()
{
	return 4 * side;
}