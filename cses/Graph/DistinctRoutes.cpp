#pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e15+5;

const int MAXN = 1005;
int parent[MAXN];
LL adj[MAXN][MAXN];
LL copy_adj[MAXN][MAXN];
bool vis[MAXN];
int N,M;
bool augment_path(){ // check if there exist a path from source 0 to sink n-1
    queue<int> q;
    memset(vis,0,sizeof(vis));
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        FOR(v,0,N) if(adj[u][v] && !vis[v]) vis[v] = 1,parent[v] = u,q.push(v);
    }
    return vis[N-1];
    
}
bool dfs(int u,VI &path){
    vis[u] = true;
    path.push_back(u+1);
    if(u==N-1) return true;
    FOR(v,0,N){
        if(!vis[v] && adj[u][v]==0 && copy_adj[u][v]){
            adj[u][v]++;
            if(dfs(v,path)) return true;
        }
    }
    return false;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    FOR(i, 0, M)
    {
        LL a, b;
        cin >> a >> b;
        adj[a-1][b-1]+=1;
        copy_adj[a-1][b-1]+=1;

    }
    LL mxflow = 0;
    while (augment_path())
    {
        LL flow = 1e8;
        for(int u=N-1;u>0;u=parent[u]){
            int v = parent[u];
            flow = min(flow,adj[v][u]);
        }
        mxflow +=flow;
        for(int u=N-1;u>0;u=parent[u]){
            int v = parent[u];
            adj[v][u] -=flow;
            adj[u][v] +=flow;

        }
    }
    
    cout << mxflow << endl;
    FOR(i,0,mxflow) {
        VI path;
        memset(vis,0,sizeof(vis));
        dfs(0,path);
        cout<<path.size()<<endl;
        trav(x,path) cout<<x<<" ";
        cout<<endl;
    }
    
    return 0;
}
