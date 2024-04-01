/***************
 * Evelyn Routon
 * May 1, 2023
 * CSC 131
 * Project 9
 * array of objects holding hostname and IP address for
 * 15 different hosts, prompt user to enter a host name
 * and check if hostname is in 'database'. if so output
 * hostname and IP address. If not output that it does
 * not exist.
 * *************/


#include <iostream>
#include <string>
using namespace std;

struct MyHost{
    string hostname;
    string IP_add;
};

int main(){
    MyHost hosts[15];
    string user_name;
    hosts[0].hostname = "www.hellotamucc.com";
    hosts[0].IP_add = "111.115.14.27";
    hosts[1].hostname = "www.hellocosc36.com";
    hosts[1].IP_add = "168.143.199.41";
    hosts[2].hostname = "www.islanders36.com";
    hosts[2].IP_add = "242.244.94.55";
    hosts[3].hostname = "www.goislanders.com";
    hosts[3].IP_add = "28.30.120.51";
    hosts[4].hostname = "www.bluetamucc.edu";
    hosts[4].IP_add = "210.21.205.183";
    hosts[5].hostname = "www.greentamucc.com";
    hosts[5].IP_add = "42.186.174.12";
    hosts[6].hostname = "www.cosc1436.com";
    hosts[6].IP_add = "66.44.172.169";
    hosts[7].hostname = "www.helloblue.com";
    hosts[7].IP_add = "178.27.160.159";
    hosts[8].hostname = "www.hellogreen.com";
    hosts[8].IP_add = "242.176.138.168";
    hosts[9].hostname = "www.gotamucc.org";
    hosts[9].IP_add = "20.208.30.151";
    hosts[10].hostname = "www.codetamucc.org";
    hosts[10].IP_add = "245.112.154.68";
    hosts[11].hostname = "www.mytamucc.edu";
    hosts[11].IP_add = "252.218.111.238";
    hosts[12].hostname = "www.theislanduni.com";
    hosts[12].IP_add = "187.214.135.204";
    hosts[13].hostname = "www.seeutamucc.com";
    hosts[13].IP_add = "81.185.145.61";
    hosts[14].hostname = "www.byetamucc.com";
    hosts[14].IP_add = "72.169.132.211";

    int x = 2;
    while(true){
        cout << "Enter a host name: ";
        cin >> user_name;
        for(int i = 0; i < 15; i++){
            if(user_name == hosts[i].hostname){
                cout << "The host name: " << hosts[i].hostname <<endl;
                cout << "The IP adress: " << hosts[i].IP_add << endl;
                x = 1;
                break;
            }else if(user_name != hosts[i].hostname){
                x = 0;
            }}
        if(x == 0){
        cout << "The hostname entered does not exist.\n";
    }   else if(x == 1){
        break;
    }
    }
    
    
}