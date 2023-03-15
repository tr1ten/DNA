// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
// #pragma GCC optimize("fast-math")

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
#define put(x) cout << x << endl;
#define put2(x, y) cout << x << " " << y << endl;
#define put3(x, y, z) cout << x << " " << y << " " << z << endl;
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
const LL MAXN=2*1e5 + 1;
const int MXK = 26;
const int P = 31;
LL pp[MAXN];

class FenwickTree
{
public:
    FenwickTree(string &s)
    {
        int n = s.size();
        tree = vector<long long>(n + 1);
        FOR(i,0,n) update(i,((s[i]-'a'+1)*pp[i])%MOD);
    }
    void update(int i, int diff)
    {
        i += 1;
        while (i < tree.size())
        {
            tree[i] = (tree[i]+diff)%MOD;
            i += i & (-i);
        }
    }
    long long _rangeSum(int i)
    {
        i += 1;
        long long sum = 0;
        while (i > 0)
        {
            sum = (sum+tree[i])%MOD;
            i -= i & (-i);
        }
        return sum;
    }
    long long rangeSum(int i, int j)
    {
        return (_rangeSum(j) - _rangeSum(i - 1) + MOD)%MOD;
    }

    vector<long long> tree;
};
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        int n,q;
        pp[0] = 1;
        cin>>n>>q;
        FOR(i,1,n) pp[i] = (pp[i - 1] * P) % MOD;
        string s;
        cin >> s;
        FenwickTree ft(s);
        reverse(all(s));
        FenwickTree rft(s);
        
        int t,j;
        FOR(i,0,q){
            cin >> t >> j;
            if(t==1){
                char k;
                cin >> k;
                ft.update(j-1,(-ft.rangeSum(j-1,j-1) + MOD+((k-'a'+1)*pp[j-1])%MOD)%MOD);
                rft.update(n-j,(-rft.rangeSum(n-j,n-j) + MOD+((k-'a'+1)*pp[n-j])%MOD)%MOD);
            }
            else{
                int k;
                cin >> k;
                LL h1 = ft.rangeSum(j-1,k-1);
                LL h2 = rft.rangeSum(n-k,n-j);
                cout <<(((h1*pp[n-k])%MOD==(h2*pp[j-1])%MOD) ? "YES" : "NO") << endl;
            }
        }
    }

    return 0;
}