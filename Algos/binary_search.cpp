#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int main(int argc, char const *argv[])
{
    
    ll lo = 0,hi = 1e10;
        ll ans = -1;
        while (lo<=hi)
        {
            ll mid = (lo+hi)/2;
            if(ok(mid)) {
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }
    return 0;
}
