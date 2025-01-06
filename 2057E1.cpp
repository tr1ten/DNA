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
struct Edge {
    int a, b, cost;
};

int n, m, v;
vector<Edge> edges;
const int INF = 1000000000;

vii solve()
{
    vector<vi> d(n, vi(n,INF));
    d[v][0] = 0;
    for (int i = 1; i < n ; ++i)
        for (Edge e : edges)
            d[e.b][i] = min(d[e.b][i-1], d[e.a][i-1] + e.cost);
    return d;
}
void testcase(){
    int q;
    cin >> n >> m >> q;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({u--,v--,w});
    }
    vector<vii> dist(n);
    rep(i,0,n){
        v=i;
        dist[i] = solve();
    }
    rep(i,0,q){
        int a,b,k;
        cin >> a >> b >> k;
        a--;b--;
        put(dist[a][b][min(k,n-1)]);

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
