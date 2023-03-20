#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef vector<int> VI;
typedef long long LL;
typedef pair<int, int> PI;
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
#define take_vec(vec, sz) FOR(i, 0, sz) cin >> vec[i];
const LL MOD = 1e9 + 7;
const int INF = 1e8 + 5;

// actual solutions
size_t solve(int n, int m, int k, VI a, VI b)
{
    int res = 0;
    map<int,int> bs;
    sort(a.begin(),a.end());
    trav(x,b) bs[x]++;
    trav(x, a)
    {
        auto iter = bs.upper_bound(x-k-1);
        // cout << bs.size() << (iter!=bs.end())  << endl;
        if(iter!=bs.end() &&  abs((*iter).first - x) <=k) {
            (*iter).second--;
            if((*iter).second==0) bs.erase(iter);
            res += 1;
        }

    }
    return res;
}

// driver code
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    mk_vec(a, n, 0);
    mk_vec(b, m, 0);
    take_vec(a, n);
    take_vec(b, m);
    cout << solve(n, m, k, a, b);
    return 0;
}
