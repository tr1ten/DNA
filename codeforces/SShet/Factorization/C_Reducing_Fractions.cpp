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

const int N = (1e7) + 5;
int sieve[N + 1];
// find prime <sqrt(MAX)
// O(LlogL)
void preprocess()
{
    sieve[0] = 1;
    sieve[1] = 1;
    for (int x = 2; x <= N; x++)
    {
        if (sieve[x] != 0)
            continue;
        sieve[x] = x;
        for (int u = 2 * x; u <= N; u += x)
        {
            sieve[u] = x;
        }
    }
}

vector<int> factors(int x)
{
    vector<int> res;
    while (x > 1)
    {
        int f = sieve[x];
            
        while (x % f == 0)
            {x /= f;
            res.push_back(f);}
    }
    return res;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    preprocess();
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int m, n;
        cin >> m >> n;
        unordered_map<int, int> c1;
        unordered_map<int, int> c2;
        vi a;
        vi b;
        rep(i, 0, m)
        {
            int x;
            cin >> x;
            trav(f, factors(x)) { c1[f]++; }
            a.push_back(x);
        }
        rep(i, 0, n)
        {
            int x;
            cin >> x;
            trav(f, factors(x)) { c2[f]++; }
            b.push_back(x);
        }
        rep(i,0,a.size()){
            trav(f,factors(a[i])){
                while(a[i]%f==0 && c2[f]){
                    a[i] /=f;
                    c2[f] -=1;
                }
            }
        }
        rep(i,0,b.size()){
            trav(f,factors(b[i])){
                while(b[i]%f==0 && c1[f]){
                    b[i] /=f;
                    c1[f] -=1;
                }
            }
        }
        put(a.size());
        put(b.size());
        pvc(a);
        pvc(b);
    }

    return 0;
}
