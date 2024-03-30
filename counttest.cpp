#include <iostream>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int main(){
//section of code to 1) get input from user 2) find tokens used in the string
    set<string> alphabet = {"a", "b", "c","d", "e", "f", "g", "h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
                            "A", "B", "C","D", "E", "F" "G", "H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z", " "};
    set<string> user_tokens;
    string text;
    cout << "Please enter a text string: ";
    getline(cin, text);
    for(int i = 0; i < text.length(); i++){
        user_tokens.insert(string(1, text[i]));
    }
    vector<string> tokens(user_tokens.size() + alphabet.size());
    auto it = set_difference(user_tokens.begin(), user_tokens.end(), alphabet.begin(), alphabet.end(), tokens.begin());
    tokens.resize(it - tokens.begin());
//end find tokens



    set<string> word_set;
    map<string, int> counter;
    string word = text;

    int wlen = 0;
    set<string>::iterator iter;
    //erase all special characters from string
    for(int i = 0; i < word.length(); i++){
        iter = tokens.find(string(1, word[i]));
        if(iter != tokens.end()){
            word.erase(i, 1);
            i--;
        }
    }
    cout << "String: " << word << endl;
}