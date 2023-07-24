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
#define put_vec(vec)  trav(x, vec) cout << x << endl; 
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
int b_len;
struct Query
{
    int l, r, idx;
    bool operator<(Query &other)
    {
            if(l/b_len != other.l/b_len)
        {
            return l < other.l;
        }
        if((l/b_len) & 1)
        {
            return r < other.r;
        }
        return r > other.r;
    }
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
        int n;
        take(n);
        VI A(n);
        take_vec(A, n);
        b_len = sqrt(n + 0.0) + 1;
        int q;
        take(q);
        vector<Query> Q;
        FOR(i, 0, q)
        {
            int l, r;
            take2(l, r);
            Q.push_back({l-1, r-1, i});
        }
        sort_vec(Q); // sort based on block index than right 
        int curL = 0, curR = -1;
        unordered_map<int, int> ans;
        int res[q];
        FOR(i, 0, q)
        {
            Query qr = Q[i];
            // add to ans datastricture
            while (curL > qr.l)
            {
                curL--;
                ans[A[curL]]++;
            }
            while (curR < qr.r)
            {
                curR++;
                ans[A[curR]]++;
            }
            // remove from ans datastructure
            while (curL < qr.l)
            {
                ans[A[curL]]--;
                if (ans[A[curL]] == 0)
                    ans.erase(ans.find(A[curL]));
                curL++;
            }
            while (curR > qr.r)
            {
                ans[A[curR]]--;
                if (ans[A[curR]] == 0)
                    ans.erase(ans.find(A[curR]));
                curR--;
            }
            res[qr.idx] = ans.size();
        }
        put_vec(res);
    }

    return 0;
}
