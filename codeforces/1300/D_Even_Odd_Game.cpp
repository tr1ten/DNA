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
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
template<typename T> 
using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
// useful defs
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define rep(N) FOR(i,0,N)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vec_sum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vec_max(vec) *max_element(vec.begin(), vec.end());
#define vec_min(vec) *min_element(vec.begin(), vec.end());
#define put_vec(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<x<<endl;
#define put2(x,y) cout<<x<<" "<<y<<endl;
#define put3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}

const LL MOD = 1e9+7;
const LL INF = 1e10+5;



// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T ;
    cin>>T;
    while(T--){
        int n;
        cin >> n;
        priority_queue<int> even;
        priority_queue<int> odd;
        rep(n){
            LL x;
            cin >> x;
            if((x%2)==1) odd.push(x);
            else even.push(x);
        }
        int A = 1;
        LL a=0,b=0;
        while(even.size() || odd.size()){
            if(A){
                if(!even.size() || (odd.size() &&  even.top()<odd.top())) odd.pop();
                else {a+=even.top();even.pop();}
            }
            else {
                if(!odd.size() || (even.size() && odd.top()<even.top())) even.pop();
                else {b+=odd.top();odd.pop();}
            }
            A ^=1;
        }
        if(a==b) put("Tie")
        else if(a>b) put("Alice")
        else put("Bob")

    }

    return 0;
}
