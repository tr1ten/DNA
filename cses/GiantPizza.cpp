#pragma GCC optimize(2, 3, "Ofast", "unroll-loops", "-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL, LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL, LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, arr) for (auto &a : (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name, sz, value) VI name(sz, value)
#define mk_mat(name, n, m, value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec, sz) FOR(i, 0, sz) cin >> vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a, b) a < b
const LL MOD = 1e9 + 7;
const LL INF = 1e10 + 5;

// actual solutions
void dfs(int u, VII &adj, vector<bool> &vis, stack<int> &st)
{
    vis[u] = true;
    trav(v, adj[u])
    {
        if (!vis[v])
            dfs(v, adj, vis, st);
    }
    st.push(u);
}
void dfs2(int u, VII &adj, VI &vis, int n)
{
    vis[u] = n;
    trav(v, adj[u])
    {
        if (vis[v]==0)
            dfs2(v, adj, vis, n);
    }
}
// 2 sat problem
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, M; // N vars and M or condition
    cin >> M >> n;
    LL N = 2*n;
    VII adj(N);
    VII radj(N);
    FOR(i, 0, M)
    {
        char x,y;
        int a, b;
        cin >> x  >> a >>y >> b;
        a--;b--;
        // aVb = !aVb |  a^!b
        if(x=='-') a+=n;
        if(y=='-') b+=n; // 0 to N-1 is true, N to 2N-1 is false
        adj[(a+n)%N].PB(b);
        adj[(b+n)%N].PB(a);
        radj[b].PB((a+n)%N);
        radj[a].PB((b+n)%N);
    }
    vector<bool> vis(N, false);
    stack<int> stk;
    FOR(i,0,N){
        if(!vis[i]) dfs(i,adj,vis,stk);
    }
    int k = 1;
    VI res(N,0);
    while(!stk.empty()){
        int u = stk.top();
        stk.pop();
        if(res[u]==0) dfs2(u,radj,res,k++);
    }
    // check if possible
    FOR(i,0,n){
        if(res[i]==res[i+n]){
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    priority_queue<PI> pq; // store component number and size
    FOR(i,0,N){
        if(res[i]!=0) pq.push(MP(res[i],i));
    }
    VI ans(n,0);
    while(!pq.empty()){
        PI p = pq.top();
        pq.pop();
        int u = p.S;
        if(ans[u%n]==0){
            ans[u%n] = (u<n)?1:-1;
        }
    }
    FOR(i,0,n) cout << (ans[i]==1 ? '+' : '-') << " ";
    cout << endl;
    return 0;
}
