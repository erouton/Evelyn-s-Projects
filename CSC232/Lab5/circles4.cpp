#include <iostream>
using namespace std;


// Evelyn Routon

class Circles
{
public:
	
	double findArea();
	double findCircumference();
	void printCircleStats();	// This outputs the radius and center of the circle. 
	Circles(float r, int x, int y);			// Constructor
    Circles(int x, int y);
    Circles(float r); //just rad
	Circles();					// Default constructor 
    ~Circles(){
        
        cout << "This concludes the Circles class\n";
    }
private:
	float	radius;
	int	center_x;
	int	center_y;
};

const double PI = 3.14;



int main()
{
	Circles sphere(8, 9, 10);
    Circles sphere1(2);
    Circles sphere2;
    Circles sphere3(15, 16);
	
    sphere.printCircleStats();
	cout << "The area of the circle is " << sphere.findArea() << endl;
	cout << "The circumference of the circle is "<< sphere.findCircumference() << endl << endl;

    sphere1.printCircleStats();
	cout << "The area of the circle is " << sphere1.findArea() << endl;
	cout << "The circumference of the circle is "<< sphere1.findCircumference() << endl << endl;

    sphere2.printCircleStats();
	cout << "The area of the circle is " << sphere2.findArea() << endl;
	cout << "The circumference of the circle is "<< sphere2.findCircumference() << endl << endl;

    sphere3.printCircleStats();
	cout << "The area of the circle is " << sphere3.findArea() << endl;
	cout << "The circumference of the circle is "<< sphere3.findCircumference() << endl << endl;

	return 0;
}



Circles::Circles(){
	radius = 1;
    center_x = 0;
    center_y = 0;
}

Circles::Circles(int x, int y){
    radius = 1;
    center_x = x;
    center_y = y;
}

Circles::Circles(float r, int x, int y){
    radius = r;
    center_x = x;
    center_y = y;
}

Circles::Circles(float r){
    radius = r;
    center_x = 0;
    center_y = 0;
}

double Circles::findArea(){
    return PI*(radius*radius);
}

double Circles::findCircumference(){
    return (2 * PI * radius);
}

void Circles::printCircleStats()
// This procedure prints out the radius and center coordinates of the circle
// object that calls it.
{
	cout << "The radius of the circle is " << radius << endl;
	cout << "The center of the circle is (" << center_x
		 << "," << center_y << ")" << endl;
}
