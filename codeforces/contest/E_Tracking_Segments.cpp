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
int n;
vi qrs;
vpi lrs;
bool ok(int x){
    if(x>=qrs.size()) return 1;
    int a[n];
    memset(a,0,sizeof a);
    rep(i,0,x+1){
        a[qrs[i]] = 1;
    }
    int pref[n+1];
    pref[0] =0 ;
    rep(i,0,n) pref[i+1] = a[i] + pref[i];
    trav(lr,lrs){
        ll ones = pref[lr.second+1] - pref[lr.first];
        if(ones>lr.second-lr.first+1-ones) return 1;
    }
    return 0;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int m;
        cin >> n >> m;
        lrs.clear();
        qrs.clear();
        rep(i,0,m){
            ll l,r;
            cin >> l >> r;
            l--;r--;
            lrs.push_back(mp(l,r));
        }
        int q;
        cin >> q;
        qrs.resize(q);
        rep(i,0,q) {
            int u;
            cin >> u;
            u --;
            qrs[i] = u;
        }
        int lo=0,hi=q-1;
        int ans = q;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(ok(mid)) {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        if(ans>q-1 || !ok(ans)) put(-1)
        else put(ans+1);


    }

    return 0;
}
