// #pragma GCC optimize(2, 3, "Ofast", "unroll-loops", "-funroll-loops")
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

// euler path
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    VII adj(N);
    VI indeg(N);
    VI outdeg(N);
    VI res;
    FOR(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        indeg[b - 1]++;
        outdeg[a - 1]++;
    }
    int start = -1;
    int end = -1;
    FOR(i, 0, N)
    {
        if(indeg[i] == outdeg[i]) continue;
        if(indeg[i]+1 == outdeg[i]) {
            if(start != -1 || i!=0) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            start = i;
        } else if(indeg[i]== outdeg[i]+1) {
            if(end != -1 || i!=N-1) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            end = i;
        } else {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    function<void(int)> dfs = [&](int u)
    {
        while (!adj[u].empty())
        {
            int v = *adj[u].rbegin();
            adj[u].pop_back();
            M--;
            dfs(v);
            res.push_back(v);
        }
    };
    if(end==-1 ||start==-1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    
    }
    dfs(0);
    if(M!=0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    res.push_back(0);
    reverse(res.begin(),res.end());
    trav(x,res) cout << (x+1) << " ";
    cout << endl;
    return 0;
}
