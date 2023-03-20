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
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    VII adj(N);
    VI coins (N,0);
    VII radj(N);
    FOR(i, 0, N) cin >> coins[i];
    FOR(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        radj[b - 1].push_back(a - 1);
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
    k--;
    // find component value
    VII cadj(k);
    VI cptval(k);
    FOR(i,0,N){
        cptval[res[i]-1] += coins[i];
        cadj[res[i]-1].push_back(i);
    }
    queue<int> q;
    VI indeg(k,0);
    FOR(i,0,k){
        trav(u,cadj[i]){
            trav(v,adj[u]){
                if(res[v]==i+1) continue;
                indeg[res[v]-1]++;
            }
        }
    }
    VI dp(k,-1);
    FOR(i,0,k){
        if(indeg[i]==0) {
            dp[i] = cptval[i];
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        trav(u,cadj[i]){
            trav(v,adj[u]){
                if(res[v]==i+1) continue;
                indeg[res[v]-1]--;
                dp[res[v]-1] = max(dp[res[v]-1],dp[i]+cptval[res[v]-1]);
                if(indeg[res[v]-1]==0) q.push(res[v]-1);
            }
        }

    }
    cout << (*max_element(dp.begin(),dp.end())) << endl;
    return 0;
}
