/***************
 * Evelyn Routon
 * April 19, 2023
 * CSC131
 * Project 7
 * Prompt user to enter 2 strings, output the length of both strings,
 * whether both strings are the same string, which string comes first 
 * alphabetically. Concatenate string 1 to string 2 and then output
 * both strings. Copy string 1 to string 2 and then output both
 * strings.
 * *************/

#include <iostream>
using namespace std;

int strlen(char *a);
char *strcpy(char *x, char *y);
char *strcat(char *x, char *y);
int strcmp(char *x, char *y);

int main(){
    char string1[50], string2[50];
    cout << "Please enter the first string: ";
    cin >> string1;
    cout << "Please enter the second string: ";
    cin >> string2;
    
    cout << "The length of string 1 is: " << strlen(string1) << endl;
    cout << "The length of string 2 is: " << strlen(string2) << endl;

    int result = strcmp(string1, string2);
    if(result == 0){
        cout << "The two strings are the same.\n";
    }
    if(result > 0){
        cout << "String 1 comes before string 2 alphabetically.\n";
    }
    if(result < 0){
        cout << "String 2 comes before string 1 alphabetically.\n";
    }
    
    strcat(string1, string2);
    cout << "String 1 after concatenation: " << string1 << endl;
    cout << "String 2 after concatenation: " << string2 << endl;

    strcpy(string1, string2);
    cout << "String 1 after copying: " << string1 << endl;
    cout << "String 2 after copying: " << string2 << endl;

}

int strlen(char *a){
    int n = 0;
    while(*a++){
        n++;}
    return n;
}

char *strcpy(char *x, char *y){
    char *start = y;
    for(; *x != '\0'; x++, y++){
        *y = *x;
    }
    *y = '\0';
    return start;
}

//adds x to end of y
char *strcat(char *x, char *y){
    char *start = y;
    for(; *y != '\0'; y++){}
    for(; *x != '\0'; x++, y++){
        *y = *x;
    }
    *y = '\0';
    return start;
}

int strcmp(char *x, char *y){
    for(int i = 0; i < 50 && *x != '\0'; i++){
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