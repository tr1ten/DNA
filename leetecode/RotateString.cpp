#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool rotateString(string s, string goal) 
{
    if(s.size()!=goal.size())
    {
        return false;
    }
    // meat
    string goaltwo =  goal + goal;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if(goaltwo.substr(i,n)==s)
        {
            return true;
        }
    }
    
    return false;
}
int main()
{
    
    return 0;
}
