#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;
void swap(string &s,int i,int j)
{
    char temp = s[j];
    s[j] = s[i];
    s[i] = temp;
}
void perm(string &s,int l, int r)
{
    if(l==r)
    {
        cout << s << endl;
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s,i,l);
        perm(s,l+1,r);
        // backtract
        swap(s,i,l);
    }
    
}
int main()
{
    string s = "ABC";
    perm(s,0,2);
    return 0;
}
