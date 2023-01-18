#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef vector<vector<int>> VVI;
typedef long long LL; 
typedef vector<LL> VI;
typedef pair<int,int> PI;
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

void print_vec(VI vec){
    trav(x,vec) cout << x << " ";
}

const LL MOD = 1e9+7;
const int INF = 1e8+5;


int numChilds(int u,int p,VI &d,VVI &adj){
    int cnt = 1;
    trav(v,adj[u]){
        if(v==p) continue;
        cnt += numChilds(v,u,d,adj);
    }
    return d[u] = cnt;
}

LL bfs(int s,VVI &adj){
    queue<int> q;
    q.push(s);
    vector<bool> vis(adj.size(),false);
    int lvl = 0; // current level
    LL dist = 0; // distance from each node
    vis[s] = true;
    while (!q.empty())
    {
        int sz = q.size();
        ++lvl;
        while (sz-->0)
        {
            int u = q.front();
            q.pop();
            trav(v,adj[u]){
                if(!vis[v]) {
                    vis[v] = true;
                    dist +=lvl;
                    q.push(v);
                }
            }
        }
    }
    return dist;
}

void f(int u,int p,VI &res,VI &childs,VVI &adj){
    res[u] = res[p]-childs[u]+(adj.size()-childs[u]);
    trav(v,adj[u]){
        if(v==p) continue;
        f(v,u,res,childs,adj);
    }
}

// actual solutions 
void solve(size_t n,vector<vector<int>> &adj){
    int S = 0;
    mk_vec(childs,n,0);
    mk_vec(res,n,0);
    res[S] = bfs(S,adj);
    numChilds(S,-1,childs,adj);
    trav(v,adj[S]) f(v,S,res,childs,adj);
    print_vec(res);
    // print_vec(childs);
    
}


// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    vector<vector<int>> adj(N);
    FOR(i,1,N){
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    solve(N,adj);
    return 0;
}