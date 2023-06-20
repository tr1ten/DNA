#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll; 
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll,ll> mll;
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) vi name(sz,value)
#define mk_mat(name,n,m,value) vector<vi> name(n, vi(m, value))
#define contains(x) find(x) != string::npos
#define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vsum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vmax(vec) *max_element(vec.begin(), vec.end());
#define vmin(vec) *min_element(vec.begin(), vec.end());
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define mod(x) (x + MOD)%MOD
const ll MOD = 1e9+7;
const ll INF = 1e10+5;
const int N = 2*(1e5) + 5;
bool vis[N];
bool path[N];
int pr[N];
ll timer;
bool isCycle;
void dfs(int u,vector<vector<pair<int,int>>> &adj){
    vis[u] = 1;
    path[u] = 1;
    trav(e,adj[u]){
        if(path[e.second]) isCycle=1;
        if(isCycle) return;
        if(vis[e.second]) continue;
        dfs(e.second,adj);
    }
    path[u] = 0;
    pr[u] = timer++;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin >> n >> m;
        memset(vis,0,sizeof vis);
        memset(path,0,sizeof path);
        timer = 0;
        vector<vector<pair<int,int>>> adj(n);
        vector<pair<int,int>> edges;
        rep(i,0,m){
            int t,u,v;
            cin >> t >> u >> v;
            --u;--v;
            const pair<int,int> e{u,v};
            edges.push_back(e);
            if(t==1) adj[u].push_back(e);
        } 
        rep(i,0,n){
            if(!vis[i]) {
                isCycle=0;
                dfs(i,adj);
                if(isCycle) break;
            }
        }
        if(isCycle) put("NO")
        else{
            put("YES")
            trav(e,edges){
                    cout << (pr[e.first]>pr[e.second] ? e.first+1 : e.second+1)<< " "  << (pr[e.first]<pr[e.second] ? e.first+1 : e.second+1) << endl;
            }
        }

    }

    return 0;
}
