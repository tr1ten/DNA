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
vector<pi> edges;
vii adj;
vi ae,av;
int n,cur;
void dfs(int u,int par,int z){
    for(auto e:adj[u]){
        int v = edges[e].first == u ? edges[e].second: edges[e].first;
        if(v!=par){
            if(z) {
                ae[e]=cur^n;
                av[v] = cur;
            }
            else {
                ae[e] = cur;
                av[v] = cur^n;
            }
            cur++;
            dfs(v,u,z^1);
        }
    }
}
void testcase(){
    int p;
    cin >> p;
    n = 1<<p;
    edges.clear();
    adj.clear();
    adj.resize(n);
    av.clear();ae.clear();
    ae.resize(n-1);
    av.resize(n);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;
        --u;--v;
        edges.push_back({u,v});
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    cur = 1;
    av[0] = n;
    dfs(0,-1,1);
    put(1);
    pvc(av);
    pvc(ae);

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
