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
#define rep(N) FOR(i, 0, N)
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
#define vec_sum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vec_max(vec) *max_element(vec.begin(), vec.end());
#define vec_min(vec) *min_element(vec.begin(), vec.end());
#define put_vec(vec)               \
    trav(x, vec) cout << x << " "; \
    cout << endl;
#define put(x) cout << (x) << endl;
#define put2(x, y) cout << (x) << " " << (y) << endl;
#define put3(x, y, z) cout << (x) << " " << (y) << " " << (z) << endl;
#define take(x) cin >> x;
#define take2(x, y) cin >> x >> y;
#define take3(x, y, z) cin >> x >> y >> z;

#define timed(x)                                                                \
    {                                                                           \
        auto start = chrono::steady_clock::now();                               \
        x;                                                                      \
        auto end = chrono::steady_clock::now();                                 \
        auto diff = end - start;                                                \
        cout << chrono::duration<double, milli>(diff).count() << " ms" << endl; \
    }

const LL MOD = 1e9 + 7;
const LL INF = 1e10 + 5;

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream &in_stream = std::cin);

struct Edge
{
    int source, destination;
    friend std::istream &operator>>(std::istream &in_stream, Edge &edge);
};
const int MX = 1e4 + 4;
VII adj;
LL mem[MX];
LL dfs(int u)
{
    if (mem[u] != -1)
        return mem[u];
    mem[u] = 1;
    trav(v, adj[u])
    {
        mem[u] = max(dfs(v) + 1, mem[u]);
    }
    return mem[u];
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::freopen("longpath.in", "r", stdin);
    std::freopen("longpath.out", "w", stdout);

    int vertex_count;
    std::cin >> vertex_count;
    adj.resize(vertex_count);
    int ec;
    cin >> ec;
    rep(ec)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
    }
    memset(mem,-1,sizeof mem);
    LL res = 0;
    FOR(u,0,vertex_count){
        res = max(dfs(u),res);
    }
    put(res-1);
    return 0;
}

std::istream &operator>>(std::istream &in_stream, Edge &edge)
{
    in_stream >> edge.source >> edge.destination;
    --edge.source, --edge.destination;
    return in_stream;
}