#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--){
        int n;
        cin >> n;
        long long sm=0;
        multiset<long long> A;
        int res=0;
        for (int i=0; i<n; i++){
            long long x;
            cin >> x;
            A.emplace(x);
            auto p = A.begin();
            sm +=x;
            if(sm<0) {
                sm -=*p;
                A.erase(p);
            }
            res = max(res,(int)A.size());
        }
        cout << res << endl;
    }
}
