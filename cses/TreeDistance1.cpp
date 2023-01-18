#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef vector<int> VI;
typedef long long LL; 
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
const LL MOD = 1e9+7;
const int INF = 1e8+5;
void f(int u,int p,int partial_ans, VI &d,VI &res ,vector<vector<int>> &adj){
    
    // or fathest node from parent that is not in this sub tree
    int nc = adj[u].size();
    mk_vec(pref,nc+1,-INF); // max prefix
    mk_vec(suff,nc+1,-INF); // max suffix

    FOR(i,1,nc+1){
        int v = adj[u][i-1];
        if(v==p) pref[i] = pref[i-1];
        else pref[i] = max(pref[i-1],d[v]);
    }
    ROF(i,0,nc){
        int v = adj[u][i];
        if(v==p) suff[i] = suff[i+1];
        else suff[i] = max(suff[i+1],d[v]);
    }
    // calculate partial ans for all childs
    FOR(i,0,nc){
        if(adj[u][i]==p) continue;
        int pa = 1 + max(max(pref[i],suff[i+1]),partial_ans);
        f(adj[u][i],u,pa,d,res,adj); // solve for child
    }
    res[u] = max(d[u],1+partial_ans); // either depth of subtree if farthest node present at the same sub tree 
}

int evalDepth(int u,int p,VI &d,vector<vector<int>> &adj){
    int lvl = 0;
    int nc  = 0;
    trav(v,adj[u]){
        if(v==p) continue;
        lvl = max(evalDepth(v,u,d,adj),lvl);
        nc++;
    }
    return nc == 0 ? d[u]=0  : d[u]=lvl+1;
}
// actual solutions 
void solve(size_t n,vector<vector<int>> &adj){
    mk_vec(d,n,0);
    mk_vec(res,n,0);
    int root = 0; // arbitrary root
    evalDepth(root,-1,d,adj);
    f(root,-1,-1,d,res,adj);
    trav(x,res){
        cout << (x) << " ";
    }
    return;
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
