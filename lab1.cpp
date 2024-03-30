#include <iostream>
#include <cmath>
using namespace std;

void DisplayMenu();
char readOperation();
float readOperand(float);
void addition(float, float);
void subtraction(float, float);
void multiply(float, float);
void divide(float, float);
void exponent(float, float);
void logb10(float);
void factorial(float);

int main(){
    float num1, num2;
    while(true){
        DisplayMenu();
        char x = readOperation();
        if(x == 'q'){
            break;
        }
        num1 = readOperand(num1);
        switch(x){
            case '+':
                num2 = readOperand(num2);
                addition(num1, num2);
                break;
            case '-':
                num2 = readOperand(num2);
                subtraction(num1, num2);
                break;
            case '*':
                num2 = readOperand(num2);
                multiply(num1, num2);
                break;
            case '/':
                num2 = readOperand(num2);
                divide(num1, num2);
                break;
            case '^':
                num2 = readOperand(num2);
                exponent(num1, num2);
                break;
            case 'l':
                logb10(num1);
                break;
            case '!':
                factorial(num1);
                break;
            default:
                cout << "Error wrong input";
                break;
        } 
    }
}

void DisplayMenu(){
    cout << "Choose one operation:\n+ addition\n- subtraction\n* multiplication\n/ division\n^ exponentation\nl base-ten logarithm\n! factorial\nq QUIT\n";
}

char readOperation(){
    char op;
    cin >> op;
    return op;
}

float readOperand(float num){
    cout << "Enter a number: ";
    cin >> num;
    return num;
}

void addition(float num1, float num2){
    float sum = 0;
    sum = num1 + num2;
    cout << "The sum of both numbers when added is " << sum << endl;
}

void subtraction(float num1, float num2){
    float sum = 0;
    sum = num1 - num2;
    cout << "The sum of both numbers when subtracted is " << sum << endl;
}

void multiply(float num1, float num2){
    float sum = 0;
    sum = num1 * num2;
    cout << "The sum of both numbers when multiplied is " << sum << endl;
}

void divide(float num1, float num2){
    float sum = 0;
    sum = num1/num2;
    cout << "The sum of both numbers when divided is " << sum << endl;
}

void exponent(float num1, float num2){
    float sum = 0;
    sum = pow(num1, num2);
    cout << "The value of both numbers when exponented is " << sum << endl;
}

void logb10(float num){
    float value = log10(num);
    cout << "The base-ten log of " << num << " is " << value << endl;
}

void factorial(float num){
    float value = 1;
    for(int i = 1; i <= num; i++){
        value *= i;
    }
    cout << "The factorial of " << num << " is " << value << endl;
}