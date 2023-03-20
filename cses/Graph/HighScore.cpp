// #pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
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
const LL INF = 1e16 + 5;

// actual solutions
LL solve(int n, vector<pair<PI, LL>> &edges)
{
    VI distTo(n, INF);
    distTo[0] = 0;
    FOR(k, 0, n)
    {
        trav(ed, edges)
        {
            int u = ed.first.first, v = ed.first.second;
            LL w = ed.second;
            if(distTo[u]==INF) continue;
            distTo[v] = max(-INF, min(distTo[u] + w, distTo[v]));
        }
    }
    // detect all nodes affected by cycle
    FOR(k, 0, n)
    {
        trav(ed, edges)
        {
            int u = ed.first.first, v = ed.first.second;
            LL w = ed.second;
            if(distTo[u]==INF) continue;
            distTo[v] = max(distTo[v], -INF);
            if (distTo[v] > distTo[u] + w)
            {
                distTo[v] = -INF; 
            }
        }
    }

    return abs(distTo[n - 1]) < INF ? -distTo[n - 1] : -1;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<pair<PI, LL>> edges;
    FOR(i, 0, M)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({{a - 1, b - 1}, -w});
    }
    cout << solve(N, edges) << endl;
    return 0;
}
