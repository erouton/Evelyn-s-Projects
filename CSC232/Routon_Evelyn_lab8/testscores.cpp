#include "NegativeScore.h"
#include "TestScores.h"

TestScores::TestScores(int scoreArray[], int size){
	numScores = size;

	scores = new int[size];

	for (int index = 0; index < size; index++){
		if (scoreArray[index] < 0 || scoreArray[index] > 100)
			throw NegativeScore(scoreArray[index]);
		else
			scores[index] = scoreArray[index];
	}}

double TestScores::getAverage() const{
	int total = 0;

	for (int index = 0; index < numScores; index++){
		total += scores[index];
	}return static_cast<double>(total) / numScores;
}