#include <cstdio>
#include <bits/stdc++.h>

using namespace std;
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// useful defs
typedef long long ll; 
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef unordered_map<ll,ll> mll;
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define per(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) vi name(sz,value)
#define mk_mat(name,n,m,value) vii name(n, vi(m, value))
#define contains(x) find(x) != string::npos
#define tkv(vec,sz) rep(i,0,sz) cin>>vec[i]
#define srv(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vsum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vmax(vec) *max_element(vec.begin(), vec.end());
#define vmin(vec) *min_element(vec.begin(), vec.end());
#define pvc(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define mod(x) (x + MOD)%MOD
// debugging
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const ll MOD = 1e9+7;
const ll INF = 1e10+5;


int main() {
    using namespace std;

    array<int, 9> cells;
    for (auto &&c : cells)
        cin >> c;

    // vertical, horizontal, and diagonal lines
    vector<tuple<int, int, int>> row{{0, 1, 2}, // 1-st row from the top
                                     {3, 4, 5}, // 2-nd row from the top
                                     {6, 7, 8}, // 3-rd row from the top
                                     {0, 3, 6}, // 1-st column from the left
                                     {1, 4, 7}, // 2-nd column from the left
                                     {2, 5, 8}, // 3-rd column from the left
                                     {0, 4, 8}, // top-left to bottom-right
                                     {2, 4, 6}};// top-right to bottom-left

    array<int, 9> order; // the i-th square is opened for the order[i]-th time
    iota(begin(order), end(order), 0);

    int not_disappoint = 0, all = 0; // the number of disappointing and total ways
    do {
        ++all;
        bool disappoint_flag = false; // determines if this order disappoints him
        for (auto &&[a, b, c] : row) // For each triple of squares (a, b, c) that is in a line
            // it's disappointing if squares a and b are equal, and c are last square to be opened within these three
            if (cells[a] == cells[b] && order[a] < order[c] && order[b] < order[c])
                disappoint_flag = true;
            // same applies for the two other pairs that can be the same digit
            else if (cells[a] == cells[c] && order[a] < order[b] && order[c] < order[b])
                disappoint_flag = true;
            else if (cells[b] == cells[c] && order[b] < order[a] && order[c] < order[a])
                disappoint_flag = true;

        // If it is not disappointing, increment the count
        if (!disappoint_flag)
            ++not_disappoint;
    } while (next_permutation(all(order))); // Try all ways to reveal it

    // Instruct to print 10 decimal places
    cout << setprecision(10);

    // Divide the number of ways that do not disappoint him by the total number of ways
    // Note that it must be calculated as a decimal
    cout << (double)not_disappoint / all << endl;

    return 0;
}
