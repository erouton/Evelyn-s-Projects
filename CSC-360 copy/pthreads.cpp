#include <pthread.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int sum;
void *runner(void *param);


int main(int argc, char * argv[]){
    pthread_t tid;
    pthread_attr_t attr;


    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join(tid, NULL);


}