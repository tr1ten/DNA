#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// a - f
// b - f 
// c - d
// d - a b 
// e -
// f - 
void dfs(char dependency,unordered_map<char,vector<char>> &dependencies,unordered_set<char> &visited){
    if(!dependency)
    {
        return;
    }
    visited.insert(dependency);
    
    for (auto dep:dependencies[dependency])
    {
        if(!visited.count(dep))
        {
            dfs(dep,dependencies,visited);
            cout << dep << endl;
        }
    }
    
}
void buildOrder(vector<char> projects,vector<vector<char>> dependencies)
{
    unordered_map<char,vector<char>> dependenciesAl;
    for (auto dependency:dependencies)
    {
        if(dependenciesAl.count(dependency[1])){
            dependenciesAl[dependency[1]].push_back(dependency[0]);
        }
        else{
            dependenciesAl[dependency[1]] = {dependency[0]};
        }
    }
    dependenciesAl[' '] = projects;
    unordered_set<char> visited;
    dfs(' ',dependenciesAl,visited);
    
    
}
int main()
{
    buildOrder({'a','b','c','d','e','f'},{{'a','d'},{'f','b'},{'b','d'},{'f','a'},{'d','c'}});
    return 0;
}
