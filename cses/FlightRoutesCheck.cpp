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
void dfs(int u, VII &adj, vector<bool> &vis, VI &st)
{
    vis[u] = true;
    trav(v, adj[u])
    {
        if (!vis[v])
            dfs(v, adj, vis, st);
    }
    st.push_back(u);
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    VII adj(N);
    VII radj[N];
    FOR(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        // radj[b - 1].push_back(a - 1);
    }
    vector<bool> vis(N, false);
    VI st;
    dfs(0, adj, vis, st);
    auto iter = find(vis.begin(), vis.end(), false);
    if (iter != vis.end())
    {
        cout << "NO" << endl;
        cout << "1"
             << " " << distance(vis.begin(),iter) << endl;
        return 0;
    }
    fill(vis.begin(), vis.end(), false);
    st.clear();
    int u = *st.rbegin();
    dfs(u, radj, vis, st);
    iter = find(vis.begin(), vis.end(), false);
    if (iter != vis.end())
    {
        cout << "NO" << endl;
        cout << (u + 1) << " " << distance(vis.begin(),iter) << endl;
    }

    return 0;
}
