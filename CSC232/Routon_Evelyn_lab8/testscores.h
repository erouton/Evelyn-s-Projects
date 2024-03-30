#ifndef TESTSCORES_H
#define TESTSCORES_H
#include <iostream>
using namespace std;

class TestScores
{
private:
	int numScores;  // Number of scores
	int *scores;    // Pointer to array of scores

public:
	TestScores()
		{ numScores = 0; scores = nullptr;}

	TestScores(int [], int);

	double getAverage() const;
};

#endif