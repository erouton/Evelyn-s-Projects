#ifndef NEGATIVESCORE_H
#define NEGATIVESCORE_H
#include <iostream>
using namespace std;

class NegativeScore{
    private:
        int value;
    public:
        NegativeScore(int v){value = v;}
        int getScore() const{return value;}
};

#endif