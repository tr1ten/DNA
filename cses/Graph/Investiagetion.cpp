#pragma GCC optimize(2, 3, "Ofast", "unroll-loops", "-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL, LL> PI;
typedef pair<PI, LL> PII;
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
const LL INF = 1e15 + 5;

void djisktra(int src, vector<vector<PI>> &adj)
{
    priority_queue<PII, vector<PII>, greater<PII>> pq; // by default max heap
    int n = adj.size();
    VI distTo(n, INF);
    VI ways(n, 0);
    VI minEdges(n, INF);
    VI maxEdges(n, -INF);
    minEdges[src] = 0;
    maxEdges[src] = 0;
    ways[src] = 1;
    distTo[src] = 0;
    pq.push({{0, 0}, src}); // cost,edges,src
    while (!pq.empty())
    {
        auto p = pq.top();
        int u = p.second;
        LL n_edges = p.first.second, cost = p.first.first;
        pq.pop();
        if (distTo[u] < cost)
            continue;
        trav(ed, adj[u])
        {
            int v = ed.first, w = ed.second;
            if (distTo[v] > distTo[u] + w)
            { // reset all values since shorter path found
                ways[v] = ways[u];
                minEdges[v] =  minEdges[u] + 1;
                maxEdges[v] =  maxEdges[u] + 1;
                distTo[v] = distTo[u] + w;
                pq.push({{distTo[v], n_edges + 1}, v});
            }
            else if (distTo[v] == distTo[u] + w)
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
                minEdges[v] = min(minEdges[v], minEdges[u] + 1);
                maxEdges[v] = max(maxEdges[v], maxEdges[u] + 1);
                
            }
        }
    }
    cout << distTo[n - 1] << " " << ways[n - 1] << " " << minEdges[n - 1] << " " << maxEdges[n - 1] << endl;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<PI>> adj(N);
    FOR(i, 0, M)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a - 1].push_back({b - 1, w});
    }

    djisktra(0, adj);
    return 0;
}
