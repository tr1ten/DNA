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
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout << x << endl;
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
int get(int a,int x){
    return a<x ? -1 : (a==x ? 0 : 1);
}
void testcase(){
    int n;
    cin >> n;
    vi a(n);
    tkv(a,n);
    vi dp(3,-INF);
    dp[0] = 0;
    rep(i,0,n){
        vi dp0(3);
        dp0[0] = dp[0] + get(a[i],dp[0]);
        dp0[1] = max(dp[0],dp[1]);
        dp0[2] = max(dp0[1],max(dp[2],dp[1]) + get(a[i],max(dp[2],dp[1])));   
        dp =dp0;
    }
    put(max(0LL,dp[2]));
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
