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
vii adj;
int n;
const int N=2005;
int dp[N][N][2];
void dfs(int u,int p) {
    int s= adj[u].size();
    rep(c,0,n+1){
        dp[u][c][1]=  dp[p][c][0] +1;
        dp[u][c][0] = 2*(s-1) +1+ dp[p][c][1];
        if(c){
            dp[u][c][0] = min(dp[u][c][0],dp[p][c-1][1]+1);
        }
    }
    for(auto v:adj[u]){
        if(v!=p){
            dfs(v,u);
        }
    }
}
void testcase(){
    int q;
    cin >> n >> q;
    adj.clear();
    adj.resize(n);
    rep(i,0,n-1){
        int u,v;
        cin >> u>> v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(auto v:adj[0]) dfs(v,0);
    rep(i,0,q){
        int v,p;
        cin >> v >> p;
        v--;
        put(dp[v][p][1]%998244353);
    }

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
