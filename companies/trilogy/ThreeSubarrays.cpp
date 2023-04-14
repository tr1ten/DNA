#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<LL> VI;
const LL INF = 1e10 + 5;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        VI A(n);
        for(int i=0;i<n;i++) cin >> A[i];
        LL pdp[n];
        pdp[0] = A[0];
        LL p = A[0];
        for(int i=1;i<n;i++)
        {
            p += A[i];
            pdp[i] = max(pdp[i - 1], p);
        }
        LL sdp[n];
        LL s = A[n - 1];
        sdp[n - 1] = A[n - 1];
        for(int i=n-2;i>=0;i--)
        {
            s += A[i];
            sdp[i] = max(sdp[i + 1], s);
        }
        LL sm=0;
        LL res = -INF;
        int i=1;
        for(int j=1;j<n-1;j++){
            sm +=A[j];
            res = max(res,(pdp[i-1]+sdp[j+1]+sm ));
            if(sm<0){
                sm =0;
                i = j+1;
            }
        }
        cout << res << endl;
    }

    return 0;
}
