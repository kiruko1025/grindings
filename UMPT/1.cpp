#include <iostream>
using namespace std;

int main(){
    int total, lBot, sBot;
    cin >> total >> lBot >> sBot;

    for(int lBotCount = total/lBot; lBotCount*lBot >= 0; lBotCount--){
        int remaining = total - lBotCount*lBot;
        if(remaining % sBot == 0){
            cout << lBotCount << ' ' << remaining/sBot;
            return 0;
        }
    }

    cout << "impossible";
    return 0;
}