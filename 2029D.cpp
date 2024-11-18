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
void testcase(){
    int n,m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    set<pi> edges;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        --u;--v;
        adj[u].insert(v);
        adj[v].insert(u);
        edges.insert({min(u,v),max(u,v)});
    }
    vii ans;
    vector<pi> other;
    while (edges.size()>1)
    {
        auto it = edges.begin();
        int u=it->first,v=it->second;
        adj[u].erase(v);
        adj[v].erase(u);
        edges.erase(it);
        
        int w=adj[u].size() ? *adj[u].begin() : (adj[v].size() ? *adj[v].begin() : -1);
        if(w==-1){
            other.push_back(*it);
            continue;
        }
        int ww=adj[u].size() ? u : v;
        int nw=adj[u].size() ? v : u;
        adj[w].erase(ww);
        adj[ww].erase(w);
        edges.erase({min(ww,w),max(ww,w)});
        if(adj[nw].count(w)){
            adj[w].erase(nw);
            adj[nw].erase(w);
            edges.erase({min(nw,w),max(nw,w)});
        }
        else {
            adj[w].insert(nw);
            adj[nw].insert(w);
            edges.insert({min(nw,w),max(nw,w)});
        }
        ans.push_back({u+1,v+1,w+1});
    }
    for(auto x:other) {
        edges.insert(x);
    }
    if(edges.size()!=0){
        auto it = edges.begin();
        int u = it->first;
        int v = it->second;
        set<int> vis = {u,v};
        rep(i,0,n){
            if(vis.count(i)==0){
                ans.push_back({u+1,v+1,i+1});
                for(auto e:adj[i]){
                    vis.insert(e);
                }
                u=v;
                v=i;
            }
        }
    }
    put(ans.size());
    for(auto v:ans){
        pvc(v);
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
