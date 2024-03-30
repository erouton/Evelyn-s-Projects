#include <iostream>
#include "TestScores.h"
#include "NegativeScore.h"
#include "testscores.cpp"
using namespace std;

const int NUM_SCORES = 5;
int main(){
    int a,b,c,d,e;
    cout << "Enter 5 test scores: ";
    cin >> a >> b >> c >> d >> e;
	try{
		int myScores[NUM_SCORES] = { 88, 90, 93, 87, 99 };

		TestScores myTestScores(myScores, NUM_SCORES);

		cout << "The average score is "
			 << myTestScores.getAverage() << endl;

		int badScores[NUM_SCORES] = { a,b,c,d,e };

		TestScores badTestScores(badScores, NUM_SCORES);

		cout << "The average score is "
			 << badTestScores.getAverage() << endl;
	}catch(NegativeScore e){
		cout << "An invalid score was found. The "
			 << "invalid score is " << e.getScore()
			 << endl;
	}
    return 0;
    }