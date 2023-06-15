#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// useful defs
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll, ll> mll;
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define per(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define trav(a, arr) for (auto &a : (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name, sz, value) vi name(sz, value)
#define mk_mat(name, n, m, value) vector<vi> name(n, vi(m, value))
#define contains(x) find(x) != string::npos
#define tkv(vec, sz) rep(i, 0, sz) cin >> vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a, b) a < b
#define vsum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vmax(vec) *max_element(vec.begin(), vec.end());
#define vmin(vec) *min_element(vec.begin(), vec.end());
#define pvc(vec)                   \
    trav(x, vec) cout << x << " "; \
    cout << endl;
#define put(x) cout << (x) << endl;
#define put2(x, y) cout << (x) << " " << (y) << endl;
#define put3(x, y, z) cout << (x) << " " << (y) << " " << (z) << endl;
#define mod(x) (x + MOD) % MOD
// debugging
#define timed(x)                                                                \
    {                                                                           \
        auto start = chrono::steady_clock::now();                               \
        x;                                                                      \
        auto end = chrono::steady_clock::now();                                 \
        auto diff = end - start;                                                \
        cout << chrono::duration<double, milli>(diff).count() << " ms" << endl; \
    }
void __print(auto x)
{
    cerr << x;
}
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    __print(x);        \
    cerr << endl;
#else
#define debug(x)
#endif
const ll MOD = 1e9 + 7;
const ll INF = 1e10 + 5;

struct node
{
    int x;
    int y;
    ll v;
    int t;
};
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        ll k;
        cin >> k;
        ll mat[n + 1][m + 1];
        rep(i, 1, n + 1)
        {
            rep(j, 1, m + 1)
            {
                cin >> mat[i][j];
            }
        }
        deque<node> dq;
        dq.push_back({1, 1, mat[1][1], 1});
        dq.push_back({m, n, mat[n][m], -1});
        int tar = min(m, n) + 1;
        unordered_map<ll, ll> c1[n+1];
        unordered_map<ll, ll> c2[n+1];
        while (!dq.empty())
        {
            node u = dq.front();
            dq.pop_front();
            if ((u.x + u.y) == tar)
            {
                if (u.t == 1)
                    c1[u.y][u.v ^ mat[u.y][u.x]]++;
                else
                    c2[u.y][u.v]++;
                continue;
            }
            if (u.x + u.t <= m && u.x + u.t > 0 )
            {
                dq.push_back({u.x + u.t, u.y, u.v ^ mat[u.y][u.x + u.t], u.t});
            }
            if (u.y + u.t <= n && u.y + u.t > 0)
            {
                dq.push_back({u.x, u.y + u.t, u.v ^ (mat[u.y + u.t][u.x]), u.t});
            }
        }
        ll res = 0;
        rep(i,1,n+1){
            trav(x, c1[i])
            {
                res += x.second * (c2[i][x.first ^ k]);
            }
            }
        put(res);
    }

    return 0;
}
