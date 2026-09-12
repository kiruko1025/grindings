#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    const int TIME = 300;

    int probCount, probStart;
    cin >> probCount >> probStart;

    vector<int> probList(probCount);

    for(int &prob : probList){
        cin >> prob;
    }

    int penalty = 0;
    int probCompleted = 0;
    int timeUse = 0;

    if(probList[probStart] > TIME){
        cout << "0 0";
        return 0;
    }

    penalty += probList[probStart];
    probCompleted++;
    timeUse += probList[probStart];

    vector<int> remaining;

    for(int i = 0; i<probCount; i++){
        if(i!=probStart){
            remaining.push_back(probList[i]);
        }
    }

    sort(remaining.begin(), remaining.end());

    for(int prob : remaining){
        if(timeUse + prob > TIME){
            cout << probCompleted << ' ' << penalty;
            return 0;
        }

        probCompleted++;
        timeUse += prob;
        penalty += timeUse;
    }

    cout << probCompleted << ' ' << penalty;
}
