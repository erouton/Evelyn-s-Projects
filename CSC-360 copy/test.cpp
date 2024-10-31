#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <deque>
#include <sstream>
#include <vector>

using namespace std;

//currently program exits fine except when, help and history are used

//want program to find each string/args. C-way. Char of pointers
/*
cout << "lsm$ ";
string cmd;
getline(cin, cmd);
 
 pid_t pid = fork();
 if (pid ==0){
    excelp(cmd.c_str(), cmd.c_str(), NULL);
 }

*/

int main () {
    deque<pid_t> hist;

    while(true){

        cout << "efr43s$ ";
        string cmd;
        getline(cin, cmd);

        stringstream ss(cmd);
        vector<string> v_cmd;
        string word;
        while(ss >> word){
            v_cmd.push_back(word);
        }

        
        for(int i= 0; i<v_cmd.size();i++){
            cout << v_cmd[i] <<endl;
        }
    }
    }
    

    


