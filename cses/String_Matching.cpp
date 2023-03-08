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

const int P = 31;
const int MAXN = 1e6 + 5;
LL pp[MAXN];
LL h[MAXN];

// actual solutions
LL rabin(string &s, string &p)
{
    int n = s.size();
    int pn = p.size();
    pp[0] = 1;
    h[0] = 0;
    FOR(i, 1, max(n,pn)) pp[i] = (pp[i - 1] * P) % MOD;
    FOR(i, 0, n) h[i + 1] = (h[i] + (s[i] - 'a' + 1) * pp[i]) % MOD;
    LL hash = 0;
    FOR(i, 0, pn) hash = (hash + (p[i] - 'a' + 1)*pp[i]) % MOD;
    int count=0;
    FOR(i, 0, n - pn + 1)
    {
        int j = i + pn - 1;
        LL cur = (h[j + 1] + MOD - h[i]) % MOD;
        if (cur == (hash * pp[i])%MOD)
            count++;
    }
    return count;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string p, t;
    cin >> t;
    cin >> p;
    cout << rabin(t, p) << endl;

    return 0;
}
