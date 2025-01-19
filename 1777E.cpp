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

const int N = 2*(1e5) + 4;

vector<int> g[N];
map<pi,int> cost;
int n,m;
bool vis[N];
int dfs(int u,int x){
    int cnt = 1;
    for(auto v:g[u]){
        if(!vis[v]){
            int c =cost[{u,v}];
            if(c<=x){
                
            }
        }
    }
}
int check(int x){
    rep(i,0,n){
        vis[i] =0;
    }
}   
void testcase(){
    cin >> n >> m;
    rep(i,0,n) g[i].clear();
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        --u;--v;
        cost[{u,v}] = 0;
        cost[{v,u}] = min(cost[{v,u}],w);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int lo=0,hi=1e9+1;
    int ans = -1;
    while (lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(check(mid)){
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
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
