#include <iostream>
using namespace std;

int main(){
    int length;
    string code, guess;
    cin >> length >> code >> guess;

    int exact = 0;
    int remainCode[26] = {};
    int remainGuess[26] = {};

    for (int i = 0; i<length; i++){
        if(code[i] == guess[i]){
            exact++;
        }else{
            remainCode[code[i] - 'A']++;
            remainGuess[guess[i] - 'A']++;
        }
    }

    int wrongPosition = 0;

    for(int i = 0; i<26; i++){
        wrongPosition += min(remainCode[i], remainGuess[i]);
    }

    cout << exact << ' ' << wrongPosition;

    return 0;
}