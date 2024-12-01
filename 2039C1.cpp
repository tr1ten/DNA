#include <bits/stdc++.h>
using namespace std;
#define ss second
#define ff first
#define int long long
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define pvc(vec) for(auto x:vec) cout<<x<<" "; cout<<endl;
#define put(x) cout << (x)<< endl;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pi;
inline int ctz(int x) { return __builtin_ctzll(x);}
inline int pc(int x) {return  __builtin_popcount(x);} 
inline int hset(int x) {return __lg(x);}
/*
    NOT use unordered map use map
    NOT use seg tree use fenwick tree
    THINK before you code
*/

int32_t main()
{
    int t;
    cin >> t;

    while (t--) {
        int x, m;
        cin >> x >> m;

        int ans = 0;
        int s_max = 1 << ((int)(log2(x) + 1)) + 1; 

        for (int s = 1; s < min(s_max, 2 * 1000000LL); ++s) {
            int y = x ^ s;
            if (y == x || y < 1 || y > m) {
                continue;
            }
            if (y % s == 0 || x%s==0) {
                ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
