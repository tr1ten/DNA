#include <bits/stdc++.h>

using namespace std;


vector<int> zfunc(string &s){
    vector<int> z(s.size());
    int l=0,r=0; // matched character range l...r
    for(int i=1;i<s.size();i++){
        if(i<=r) z[i] = min(r-i+1,z[i-l]);
        while(i+z[i]<s.size() && s[i+z[i]]==s[z[i]]) z[i]++;
        if(i+z[i]-1>r){
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}
int main(int argc, char const *argv[])
{
    return 0;
}