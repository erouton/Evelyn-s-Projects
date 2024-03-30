//Ackermann's Function
//If m=0 then return n+1
//If n=0 then return A9m-1,1)
//Otherwise, return A(m-1, A(m, n-1))
//Write a function A(m, n) that solves Ackermann's Function
#include <iostream>
using namespace std;

int A(int, int);

int main(){
	cout << "A(0,0) = " << A(0,0) << endl;
	cout << "A(0,1) = " << A(0,1) << endl;
	cout << "A(1,1) = " << A(1,1) << endl;
	cout << "A(1,2) = " << A(1,2) << endl;
	cout << "A(1,3) = " << A(1,3) << endl;
	cout << "A(2,2) = " << A(2,2) << endl;
	cout << "A(3,2) = " << A(3,2) << endl;
}

int A(int m, int n){
	if(m==0)
		return n+1;
	else if(n==0)
		return A(m-1, 1);
	else
		return A(m-1, A(m, n-1));
}