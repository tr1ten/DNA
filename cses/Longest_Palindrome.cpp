#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")

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
typedef vector<int> VI;
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

// similar to z array
VI manchers_odd(string &s){
    int n = s.size();
    VI pi(n,0); // pi[i] length of largest pali at center i including self
    int l=0,r=0; // this are exclusive for conviences
    FOR(i,0,n){
        pi[i] = max(0,min(r-i,pi[l+r-i]));
        while(i-pi[i]-1>=0 && i+pi[i]+1<n && s[i-pi[i]-1]==s[i+pi[i]+1]) pi[i]++;
        if(i+pi[i]>r){
            l = i-pi[i];
            r = i+pi[i];
        }
    }
    return pi;
}
// actual solutions
void solve(string &s)
{
    int n = s.size();
    string ns;
    trav(c,s) {
        ns += string("#") + c;
    }
    ns +='#';
    VI pi = manchers_odd(ns);
    int lc=0,lp=0;
    FOR(i,0,pi.size()){
        if(pi[i]>pi[lc]) lc=i;
    }
    string res = ns.substr(lc-pi[lc],2*pi[lc]+1);
    res.erase(remove(all(res),'#'),res.end());
    put(res);

}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}