#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

const int MAXEMP = 4;

struct EmployeeInfo {
    string first;
    string last;
    int ssn;
    int id;
    int years;
    double salary;
};

int main(){
    EmployeeInfo employee[MAXEMP];
    fstream inFile, outFile, binFile;
    inFile.open("employee.in", ios::in);
    outFile.open("employee.out", ios::out);
    binFile.open("employee.dat", ios::binary | ios::out);

    outFile << "Name" << setw(25) << "Social Security" << setw(15) << "Department ID"
                << setw(13) << "Years Employed" << setw(13) << "Salary" << endl << endl;

    string inputstr;
    int inputint;
    double inputdoub;
    
    int emp_count = 0;
    if(inFile){
        while(emp_count < MAXEMP){
            inFile >> inputstr;
            outFile << inputstr << " ";
            employee[emp_count].first = inputstr;
            binFile.write((char *)&inputstr, sizeof(inputstr));

            inFile >> inputstr;
            outFile << inputstr << setw(15);
            employee[emp_count].last = inputstr;
            binFile.write((char *)&inputstr, sizeof(inputstr));

            inFile >> inputint;
            outFile << inputint << setw(12);
            employee[emp_count].ssn = inputint;
            binFile.write((char *)&inputint, sizeof(inputint));

            inFile >> inputint;
            outFile << inputint << setw(10);
            employee[emp_count].id = inputint;
            binFile.write((char *)&inputint, sizeof(inputint));

            inFile >> inputint;
            outFile << inputint << setw(20);
            employee[emp_count].years = inputint;
            binFile.write((char *)&inputint, sizeof(inputint));

            inFile >> inputdoub;
            outFile << inputdoub << endl;
            employee[emp_count].salary = inputdoub;
            binFile.write((char *)&inputdoub, sizeof(inputdoub));

            emp_count++;
        }
        inFile.close();
    }else{
        cout << "Error, file does not exist.\n";
    }
    int year_count = 0, sal_count = 0;
    for(int i = 0; i < emp_count; i++){
        year_count += employee[i].years;
        sal_count += employee[i].salary;
    }
    year_count/=(year_count+1);
    sal_count/=(sal_count+1);
    outFile << endl << "The average number of years employed is " << year_count << endl;
    outFile << "The average salary is $" << sal_count << endl;
}