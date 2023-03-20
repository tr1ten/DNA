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
LL MXN  = 1e6 + 1;
LL dp[1000001][2] = {0};
// actual solutions
void solve()
{
    dp[1][0] = 1; // if not vertical bar at ith height
    dp[1][1] = 1; // if vertical bar
    FOR(i,2,MXN){
        dp[i][0] = (dp[i-1][0]*2+dp[i-1][1])%MOD;
        dp[i][1] = (dp[i-1][1]*4 + dp[i-1][0])%MOD;
    }
}

// driver code
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    solve();
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int N;
        cin >> N;
        cout << (dp[N][0]+dp[N][1])%MOD << endl;
    }

    return 0;
}
