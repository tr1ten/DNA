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
const int N = 5*1e5 + 5;
vi g[N];
int a[N];
int dp[N];
int ans;
void dfs(int u,int par){
    vi cc;
    vi sum(4,-INF);
    sum[0] = 0;
    for(auto v:g[u]){
        if(v!=par){
            dfs(v,u);
            for (int i = 3; i >= 0; --i) {
                sum[min(i + 1, 3LL)] = max(sum[min(i + 1, 3LL)], sum[i] + dp[v]);
            }

        }
    }
    dp[u]=-INF;
    rep(j,0,4){
        dp[u] = max(dp[u], sum[j] + (j == 1 ? 0 : a[u]));
        ans = max(ans, sum[j] + (j == 2 ? 0 : a[u]));
    }
}
void testcase(){
    int n;
    cin >> n;
    tkv(a,n);
    rep(i,0,n){
        g[i].clear();
        dp[i] = 0;
    }
    ans = 0;
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0,-1);
    put(ans);

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
