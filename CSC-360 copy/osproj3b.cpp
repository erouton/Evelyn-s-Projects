#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Shared data structure
int *fibonacciSequence;
int numFib;

// Function to generate Fibonacci sequence
void *generateFibonacci(void *arg) {
    fibonacciSequence[0] = 0;  // First Fibonacci number
    if (numFib > 1) {
        fibonacciSequence[1] = 1;  // Second Fibonacci number
        for (int i = 2; i < numFib; i++) {
            fibonacciSequence[i] = fibonacciSequence[i-1] + fibonacciSequence[i-2];
        }
    }
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Incorrect number of command line arguments entered\n";
        return 1;
    }
    numFib = atoi(argv[1]);
    if (numFib < 1) {
        cerr << "Fibonacci numbers must be greater than 0\n";
        return 1;
    }

    // Allocate memory for the Fibonacci sequence
    fibonacciSequence = (int *)malloc(numFib * sizeof(int));
    if (fibonacciSequence == NULL) {    return 1;   }

    pthread_t fibThread;

    if (pthread_create(&fibThread, NULL, generateFibonacci, NULL) || pthread_join(fibThread, NULL)) {
        //error occurred
        free(fibonacciSequence);
        return 1;
    }


    // Output the Fibonacci sequence
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < numFib; i++) {
        cout << fibonacciSequence[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    free(fibonacciSequence);

    return 0;
}
