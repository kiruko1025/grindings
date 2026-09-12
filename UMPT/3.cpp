#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int,int> root, sz;

int findRoot(int ingredient){
    if(!root.count(ingredient)){
        root[ingredient] = ingredient;
        sz[ingredient] = 1;
    }
    return root[ingredient] == ingredient ? ingredient
        : root[ingredient] = findRoot(root[ingredient]);
}

int main(){
    int totalRecipe, concoctedRecipe = 0;
    cin >> totalRecipe;

    while(totalRecipe--){
        int numberIngredients;
        cin >> numberIngredients;
        unordered_map<int,int> ingredientFromConcocted;
        while(numberIngredients--){
            int ingredient;
            cin >> ingredient;
            ingredientFromConcocted[findRoot(ingredient)]++;
        }

        bool possible = true;
        for(auto [r, count] : ingredientFromConcocted)
            if(count != sz[r]) possible = false;
        if(!possible) continue;
        concoctedRecipe++;
        if(ingredientFromConcocted.empty()) continue;
        int largest = ingredientFromConcocted.begin()->first;
        for(auto [r, count] : ingredientFromConcocted)
            if(sz[r] > sz[largest]) largest = r;
        for(auto [r, count] : ingredientFromConcocted){
            root[r] = largest;
            if(r != largest) sz[largest] += count;
        }
    }
    cout << concoctedRecipe << '\n';
}
