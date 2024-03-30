#include <iostream>
#include <string>
using namespace std;

// Function prototype
bool isPalindrome(string, int, int);

int main()
{
	const int SIZE = 6;

    // Create an array of strings to test.
    string testStrings[SIZE] = 
	        { "ABLE WAS I ERE I SAW ELBA",
              "FOUR SCORE AND SEVEN YEARS AGO",
              "NOW IS THE TIME FOR ALL GOOD MEN",
              "DESSERTS I STRESSED",
              "AKS NOT WHAT YOUR COUNTRY CAN DO FOR YOU",
              "KAYAK" };
   
   // Test the strings.
   for (int i = 0; i < SIZE; i++)
   {
      cout << "\"" << testStrings[i] << "\"";
	  if (isPalindrome(testStrings[i], 0, (testStrings[i].length()-1)))
		  cout << " is a palindrome.\n";
	  else
		  cout << " is NOT a palindrome.\n";
   }
 
	return 0;
}

//*******************************************
// The isPalindrome function returns true   *
// the argument is a palindrome, false      *
// otherwise.                               *
//*******************************************

//if first half is equal to second half


bool isPalindrome(string str, int b, int e){
	bool status;
	if(str[b] != str[e])	
		return status = false;
	else if(b == e)
		return status = true;
	else{
		return isPalindrome(str, b+1, e-1);
	}
}



