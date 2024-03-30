#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
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
    cout << "The difference is: ";
    for (auto element : tokens){
        cout << element << " ";
    }cout << endl;

}