#include <iostream>
#include <vector>
#include <string>
using namespace std;
string compressString(const string s)
{ 
    string res;
    int count;
    int p1=0;
    while(p1<s.size())
    {
        char key = s[p1];
        p1++;
        count = 1;
        while(p1<s.size() && s[p1]==key)
        {
            count++;
            p1++;
        }
        res.push_back(key);
        if(count>1){
            res = res + to_string(count);
        }
    }
    return res.size() < s.size() ? res : s;
}
int main()
{
    cout << compressString("shubhhh"); 
    return 0;
}
