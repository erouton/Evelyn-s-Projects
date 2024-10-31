/* ********************************************************
*
* Evelyn Routon
* CSC360/660 Operating Systems
* Project #1: My Shell - Writing Your Own Shell
* This shell supports the following commands: help, exit, history
*
* ******************************************************** */

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <deque>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    //using deque to store history
    deque<pid_t> hist;

    while(true){

        //read command from user
        cout << "efr43s$ ";
        string cmd;
        getline(cin, cmd);

        stringstream ss(cmd);
        vector<string> v_cmd;
        string word;
        while(ss >> word){
            v_cmd.push_back(word);
        }




        //continue if there is nothing entered, i.e spaces or enter/newline
        if(cmd.size() == 0){
            continue;
        }

        //exit when command is 'exit', and confirm if the command is close to 'exit'
        if(cmd == "exit"){
            exit(0);
        }else if(cmd == "eixt" || cmd == "xeit" || cmd == "exti" || cmd == "eit" || cmd == "xit" || cmd == "exi"){
            cout << "Did you mean 'exit'? (Y/N) \n";
            string confirm;
            getline(cin, confirm);
            if(confirm == "Y"){
                exit(0);
            }else{
                continue;
            }
        }


        pid_t pid = fork();


        vector<char*> args;
        for (size_t i = 0; i < v_cmd.size(); ++i) {
            args.push_back(&v_cmd[i][0]);
        }
        args.push_back(nullptr);
    

        if(pid < 0){
            cout << "Error: Process failed" << endl;
            return 1;

        }else if(pid == 0){   //child process is pid == 0
            //execlp(cmd.c_str(), cmd.c_str(), NULL);
            execvp(args[0], args.data());
            return 0;

        }else if(pid > 0){

            //store pid in history, if history is less than 5 just push to front. if history size is >= to 5, pop last value and then push to front.
            if(hist.size() < 5){
                hist.push_front(getpid());
            }else if(hist.size() >= 5){
                hist.pop_back();
                hist.push_front(getpid());
            }

            //wait for child process
            wait(NULL);
            
        }

        
        if(cmd == "help"){

            cout << "*********************************************************\n\n Evelyn Routon\n CSC360/660 Operating Systems\n Project #1: My Shell - Writing Your Own Shell\n This shell supports the following commands: help, exit, history\n\n*********************************************************\n";
        }else if(cmd == "history"){
            //iterate through deque to output history if command is called
            deque<pid_t>::iterator it = hist.begin();  
            while (it != hist.end()){
                cout << "   " << *it++ << endl;
            }
        }

    }
    
}