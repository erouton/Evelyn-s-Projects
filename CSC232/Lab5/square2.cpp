// This program declares the Square class and uses member functions to find
// the perimeter and area of the square

// Evelyn Routon

#include <iostream>
using namespace std;

class Square{
    public:
        Square(); 
        Square(float);
        
        ~Square(){}  

        void setSide(float);
        float findArea();
        float findPerimeter();  
        float side; 
        
};

int main()
{   
    float size;
    cout << "Please input the side of the square ";
    cin >> size;
	Square box(size);	// box is defined as an object of the Square class
    cout << "The area of the square is " << box.findArea() << endl;
    cout << "The perimeter of the square is " << box.findPerimeter() <<endl;

    Square box1(9);
    cout << "The area of box1 is " << box1.findArea() << endl;
    cout << "The perimeter of box1 is " << box1.findPerimeter() << endl;

	return 0;
}

Square::Square(){
    side = 1;
}


Square::Square(float length){
    side = length;
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