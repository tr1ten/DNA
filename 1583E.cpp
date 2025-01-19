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
const int N = 3*(1e5)+5;
vi g[N];
vi st[N];
int n,m;
int f[N];
vector<pi> edges;
class DSU
{
public:
    int *par;
    int *sz;
    DSU(int n)
    {
        this->par = new int[n];
        this->sz = new int[n];
        for (int i = 0; i < n; i++)
        {
            this->par[i] = i;
            this->sz[i] = 1;
        }
    }
    int find(int x)
    {
        int p = x;
        while (p != this->par[p])
        {
            p = par[p];
        }
        return p;
    }
    void connect(int u, int v)
    {
        int rootu = find(u);
        int rootv = find(v);
        if (rootu == rootv)
            return;
        if (sz[rootu] < sz[rootv])
        {
            par[rootu] = rootv;
            sz[rootv] += sz[rootu];
        }
        else
        {
            par[rootv] = rootu;
            sz[rootu] += sz[rootv];
        }
    }
};
int dfs(int u, int t,int par,vi &path){
    path.push_back(u+1);
    if(u==t) return 1;
    for(auto v:st[u]){
        if(v!=par){
            if(dfs(v,t,u,path)){
                return 1;
            }
        }
    }
    path.pop_back();
    return 0;
}
void testcase(){
    cin >> n >> m;

    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        --u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
        edges.push_back({u,v});
    }
    int q;
    cin >> q;
    vector<pi> qrs;
    rep(i,0,q){
        int u,v;
        cin >> u >> v;
        --u;--v;
        qrs.push_back({u,v});
        f[u]++;
        f[v]++;
    }
    int odc=0;
    rep(i,0,n){
        odc +=f[i]%2;
    }
    if(odc){
        put("NO");
        put(odc/2);
    }
    else {
        DSU ds(n);
        
        rep(i,0,m){
            auto [u,v] = edges[i];
            if(ds.find(u)!=ds.find(v)){
                st[u].push_back(v);
                st[v].push_back(u);
                ds.connect(u,v);
            }
        }
        put("YES");
        rep(i,0,q){
            vi path;
            dfs(qrs[i].first,qrs[i].second,-1,path);
            put(path.size());
            pvc(path);
        }

    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);      
    int T=1;
    while(T--) testcase();

    return 0;
}
