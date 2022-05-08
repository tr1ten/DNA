#include <iostream>
#include <vector>
#include <string>
using namespace std;
void rec(string initial,const string &target,int i,vector<string> &powerset)
{
    if(i>=target.size())
    {
        powerset.push_back(initial);
        return;
    }
    rec(initial,target,i+1,powerset);
    initial.push_back(target[i]);
    rec(initial,target,i+1,powerset);
}
int main()
{
    vector<string> powerset;
    rec("","huh",0,powerset);
    for (auto v:powerset)
    {
        cout << v << endl;
    }
    
    return 0;
}
