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
#define mk_mat(name,n,m,value) vector<vi> name(n, vi(m, value))
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
void __print(auto x) {cerr << x;}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; __print(x); cerr << endl;
#else
#define debug(x)
#endif
const ll MOD = 1e9+7;
const ll INF = 1e10+5;
// driver code
// Very good binary search question
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        ll n,m;
        cin >> n >> m;
        vi A(n);
        tkv(A,n);
        srv(A);
        auto ok = [&] (ll x){ // find number of pairs having sum greater than or eq to x
            ll cnt = 0;
            trav(k,A){
                cnt +=A.end()- lower_bound(all(A),x-k); 
            }
            // debug(x)
            // debug(cnt)
            return cnt;
        };
        ll lo =0,hi = 2*A[n-1];
        ll ans = hi;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            if(ok(mid)>=m) {
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }
        vi pref(n+1);
        partial_sum(A.rbegin(),A.rend(),pref.begin()+1);
        ll res = 0;
        ll cnt = ok(ans); // normal this should be eq to m else we have to substract some ans to make it m
        trav(k,A){
                ll to = A.end()- lower_bound(all(A),ans-k);
                res +=k*to + pref[to]; 
        }
        // debug(ok(ans))
        // debug(ans);
        put(res-(cnt-m)*ans);
    }

    return 0;
}
