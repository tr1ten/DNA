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
const int INF = 1e6 + 5;

// actual solutions
LL solve(int n, VI &vec)
{
    return n;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    VII adj(N);
    FOR(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    queue<int> q;
    int dist[N];
    int par[N];
    memset(dist, INF, sizeof(dist));
    memset(par, -1, sizeof(par));

    dist[0] = 1;
    par[0] = 0;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == N - 1)
            break;
        trav(v, adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
    if (dist[N - 1] <= N)
    {
        cout << dist[N - 1] << endl;
        int i = N-1;
        stack<int> st;
        while (par[i]!=i)
        {
            st.push(i+1);
            i  = par[i];
        }
        st.push(1);
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}