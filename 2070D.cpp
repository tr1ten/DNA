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
const int MOD = 998244353; // change me for god sake look at problem mod
const int INF = 1e16+5;
const int N = 3*(1e5) + 5;
vi g[N];
int dt[N];
void dfs(int u,int d) { 
    dt[u] = d;
    for(auto v:g[u]){
        dfs(v,d+1);
    }
}
int dpall[N],dp[N];
void testcase(){
    int n;
    cin >> n;
    rep(i,1,n){
        int u;
        cin >> u;
        u--;
        g[u].push_back(i);
    }
    dfs(0,0);
    vi inds(n);
    iota(all(inds),0);
    sort(all(inds),[&](int u,int v){
        return dt[u] > dt[v];
    });
    for(auto v:inds){
        int d = dt[v];
        dp[v] = (dpall[d+1]+1)%MOD;
        if(v){
            for(int u:g[v]){
                dp[v] -= dp[u];
                dp[v] += MOD;
                dp[v] %=MOD;
            }
        }
        dpall[d] += dp[v];
        dpall[d] %=MOD;
        // cout << v <<"  " << dp[v] << endl;
    }
    rep(i,0,n){
        dp[i]=0, dpall[i] = 0;
        g[i].clear();
    }
    put(dp[0]);
    
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
