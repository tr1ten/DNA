#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isPerm(string original,string p)
{
    // assuming lowercase
    int hashmap[27]={0};
    for (auto c:original)
    {
        int val = c - 'a';
        hashmap[val]++;
    }
    for (auto c:p)
    {
        int val = c - 'a';
        hashmap[val]--;
    }
    for (int i = 0; i < 27; i++)
    {
        if(hashmap[i]!=0)
        {
            return false;
        }
    }
    return true;
    
    
    
    
}
int main()
{
    cout << isPerm("shubh","hsubh");
    return 0;
}
