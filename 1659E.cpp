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


void testcase(){
    int n,m;
    cin >> n >> m;
    vector<vector<pi>> adj(n);
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;    
        u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<DSU*> ds1(30);
    vector<DSU*> ds2(30);
    rep(j,0,30){
        ds1[j] = new DSU(n);
        ds2[j] = new DSU(n+1);

    }
    rep(i,0,n){
        int ev = 0;
        for(auto [v,w]:adj[i]){
            if((w&1)==0){
                ev=1;
            }
            rep(j,0,30){
                if((w>>j)&1){
                    ds1[j]->connect(i,v);
                    ds2[j]->connect(i,v);
                }
            }
        }
        if(ev){
            rep(j,0,30){
                ds2[j]->connect(i,n);
            }
        }
    }
    int q;
    cin >> q;
    rep(i,0,q){
        int u,v;
        cin >> u>> v;
        --u;--v;
        int f = 0;
        rep(j,0,30){
            if(ds1[j]->find(u)==ds1[j]->find(v)){
                // cout << u << " " << v << " " << j << "=found" << endl;
                put(0);
                f=1;
                break;
            }
        }
        if(!f){
            rep(j,1,30){
                if(ds2[j]->find(u)==ds2[j]->find(n)){
                    put(1);
                    f=1;
                    break;
                }
            }
            if(!f){
                put(2);
            }
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
