#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include <string>

using namespace std;
//Class to implement Temperature object
class Temperature
{
    private:
        double degree;//instance variable
        char scale;
    public:
		//Begin constructors
        Temperature(){
            setDegree(0);
            setScale('C');
        }
        Temperature(double a, char b){
            setDegree(a);
            setScale(b);
        }
		//End constructors
		//Begin setters and getters
		double getDegree(){
            return degree;
        }
		char getScale(){
            return scale;
        }
		void setDegree(double t){
            degree = t;
        }
		void setScale(char c){
            scale = c;
        }
		//End setters and getters
		//Begin operator overloading
		double operator-(Temperature& rval){
            Temperature temp;
            temp.degree = degree - rval.degree;
            return temp.degree;
        }
		bool operator<(Temperature& rval){
            bool status;
            if(degree < rval.degree){
                status = true;
            }else if(degree > rval.degree){
                status = false;
            }
            return status;
        }
		bool operator>(Temperature& rval){
            bool status;
            if(degree > rval.degree){
                status = true;
            }else if(degree < rval.degree){
                status = false;
            }
            return status;
        }
		bool operator==(Temperature& rval){
            bool status;
            if(degree == rval.degree){
                status = true;
            }else if(degree != rval.degree){
                status = false;
            }
            return status;
        }
		bool operator!=(Temperature& rval){
            bool status;
            if(degree != rval.degree){
                status = true;
            }else if(degree == rval.degree){
                status = false;
            }
            return status;
        }
		friend ostream& operator<<(ostream& out, const Temperature& T){
            out << T.degree << " degrees, " << T.scale << " scale\n";
            return out;
        }
		friend istream& operator>>(istream& in, Temperature& T){
            cout << "Degrees: ";
            in >> T.degree;
            cout << "Scales: ";
            in >> T.scale;
            return in;
        }
		//End operator overloading
		//Begin helper functions
		double tempConverter(Temperature& T, char convertTo){
            if(convertTo == 'C'){T.degree -= 273.15; T.scale = 'C';}
            if(convertTo == 'K'){T.degree += 273.15; T.scale = 'K';}
            return T.degree;
        }
};

#endif