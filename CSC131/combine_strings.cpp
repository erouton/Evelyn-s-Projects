/******************
 * Evelyn Routon
 * April 26, 2023
 * CSC131
 * Project 8
 * Prompt user to enter 2 string with maximum of 30 characters,
 * combine the string either interchangeably, or by appending
 * the second to the first but also inserting asteriks between
 * every character. Examples of both:
 *    String1: abcdef
 *    String2: 12345
 * 1) Output: a1b2c3d4e5f
 * 2) Output: a*b*c*d*e*f*1*2*3*4*5
 * Either way is indicated by command line arguments with the 
 * 1st way denoted by 'i' and 2nd way by 'w'. Example:
 * ./a.out -i
 * ./a.out -w
 * ***************/

#include <iostream>
#include <stdlib.h>
using namespace std;
char *intersperse(char *x, char *y);
char *widen_stars(char *x, char *y);
int strlen(char *a);

int main(int argc, char* argv[]){
    char str1[30], str2[30];
    for(int i = 0; i < argc; i++){
        cout << argv[i] << ' ';
    }
    cout << "\nPlease enter a string of maximum 30 characters: ";
    cin >> str1;
    cout << "Please enter a string of maximum 30 characters: ";
    cin >> str2;
    
    if(argv[1][1] == 'i'){
        char *temp;
        temp = intersperse(str1, str2);
        cout << "The combined string is: " << temp << endl;
        free(temp);
    }
    if(argv[1][1] == 'w'){
        char *temp;
        temp = widen_stars(str1, str2);
        cout << "The combined string is: " << temp << endl;
        free(temp);
    }
}


int strlen(char *a){
    int n = 0;
    while(*a++){
    n++;}
    return n;
}


int strcmp(char *x, char *y, int size){ 
    for(int i = 0; i < size && *x != '\0'; i++){
        if(*y == '\0'){
            return -1;
        }
        if(*x < *y){
            return 1;
        }
        if(*x > *y){
          return -1;
        }
        x++;
        y++;
        }
    if(*y != '\0'){
        return 1;
    }
    return 0;
}


char *intersperse(char *x, char *y){
    int length = strlen(x) + strlen(y);
    char *newstr;
    newstr = new char[length + 1];
    int i = 0;
    for(; i < length; i++, x++, y++){
        newstr[i] = *x;
        i++;
        newstr[i] = *y;
        if(*x == '\0'){
            for(y++; i < length+1; i++, y++){
                newstr[i] = *y;}
            return newstr;
        }
        if(*y == '\0'){
            for(x++; i < length+1; i++, x++){
                newstr[i] = *x;}
            return newstr;
    }
    } return newstr; 
}


char *widen_stars(char *x, char *y){
    int xlen = strlen(x);
    int ylen = strlen(y);
    int length = 2 * (xlen + ylen);
    char *newstr;
    newstr = new char[length];
    int i = 0;
    for(; i < (2 * xlen)-1; i++, x++){
        newstr[i] = *x;
        i++;
        newstr[i] = '*';      
    }
    for(; i < length-1; i++, y++){
        newstr[i] = *y;
        i++;
        newstr[i] = '*';}
    i--;
    newstr[i] = 0;
     return newstr; 
}
