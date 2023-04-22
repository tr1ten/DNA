#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
string add(string s1,string s2){
    
}
int main(int argc, char const *argv[])
{
    auto ok = [&](LL k)
    {
        return false;
    };
    LL r = 0;
    // for finding max x that satisfy ok
    for (int i = 62; i >= 0; --i)
    {
        if (ok(r + (1LL << i))) // check if we can add this bit 
            r += (1LL << i); // add binary bit
    }

    return 0;
}
