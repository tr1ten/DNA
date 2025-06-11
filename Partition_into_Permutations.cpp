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

const int MOD = 1e9+7; // change me for god sake look at problem mod
const int INF = 1e16+5;
void testcase(){
    int n;
    cin >> n;
    vi a(n);
    tkv(a,n);
    srv(a);
    int i =0;
    int ans = 0;
    int mx = 2*n;
    vector<int> cnt(mx+1);
    rep(i,0,n){
        if(a[i]<=mx) cnt[a[i]]++;
        else ans++;
    }
    vector<int> dp(mx+1);

    rep(i,1,mx+1){
        vector<int> dp0(mx/i + 2);
        dp0[mx/i + 1] = INF;
        per(c,0,mx/i + 1){
            dp0[c] = min(abs(c-cnt[i]) + dp[c], dp0[c+1]);
        }
        dp = dp0;
    }
    int ma = INF;
    for(auto v:dp){
        ma = min(v,ma);
    }
    put(ans + ma);
    
    
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    cin>>T;
    while(T--) testcase();

    return 0;
}
