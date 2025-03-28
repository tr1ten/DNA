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
const int N = 1e5 + 5;
int masks[N];
vector<pi> g[N];
int dp[1<<20 + 1];
bool dfs(int u,int p,int end,int b){
    if(end==u) return true;
    for(auto v:g[u]){
        if(v.first!=p){
            if(dfs(v.first,u,end,b)){masks[v.second] |= b;return true;}
        }
    }
    return false;
}   
void testcase(){
    int n;
    cin >> n;
    rep(i,0,n) {g[i].clear();masks[i]=0;}
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    int k;
    cin >> k;
    rep(i,0,k){
        int u,v;
        cin >> u >> v;
        --u;--v;
        dfs(u,-1,v,1<<i);
    }
    unordered_set<int> st;
    rep(i,0,n-1){
        st.insert(masks[i]);
    }
    rep(i,0,1<<k) dp[i] = INF;
    dp[0] = 0;
    for(int ai:st){
        rep(j,0,1<<k){
            dp[j|ai] = min(dp[j|ai], dp[j] + 1);
        }
    }
    put(dp[(1<<k)-1]);
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
