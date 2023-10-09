#include <bits/stdc++.h>
#include "Decimal.h"

using namespace std;

string solve(string s){
    s +=" ";
    string delimiter = " ";

    size_t pos = 0;
    std::string token;
    map<string,int> mp;
    mp["zero"] = 0;
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
    mp["four"] = 4;
    mp["five"] = 5;
    mp["six"] = 6;
    mp["seven"] = 7;
    mp["eight"] = 8;
    mp["nine"] = 9;
    map<string,int> kmp;

    kmp["double"] = 2;
    kmp["triple"] = 3;
    string res;
    int cur = 1;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        if(kmp.count(token)) {
            cur = kmp[token];
        }
        else {
            while(cur-->0) {
                res += to_string(mp[token]);
            }            
            cur= 1;
        }

        s.erase(0, pos + delimiter.length());
        
    }
    return res;
}
int main(int argc, char const *argv[])
{
    cout << solve("one two three double two one triple three one");
    return 0;
}
