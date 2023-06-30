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
#define mod(x) ((x)%MOD + MOD)%MOD
// debugging
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}
void __print(auto x) {cerr << x;}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; __print(x); cerr << endl;
#else
#define debug(x)
#endif
const ll MOD = 2760727302517;
const ll INF = 1e10+5;

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    rep(t,0,T){
        ll n,q;
        cin >> n >> q;
        vi A(n+1);
        vi pref;
        pref.push_back(0);
        ll t1=0,t2=0,c=0;
        rep(i,1,n+1){
            ll x;
            cin >> x;
            A[i] = x;
            t1 = mod(t1 + (n-i+1)*mod(x*x));
            t2 = mod(t2+mod(i*x*x));
            pref.push_back(mod(pref.back() + x));
        }
        rep(i,1,n+1){
            c = mod(c+mod(A[i]*mod(pref[n] - pref[i-1])) );
        }
        ll sm = pref[n];
        cout << "Case " << (t+1) << ":\n";
        while(q-->0){
            int tt;
            cin >> tt;
            switch(tt){
                case 1:{
                    ll x,v;
                    cin >> x >> v;
                    t1 = mod(t1-mod((n-x+1)*mod(A[x]*A[x]))+mod(n-x+1)*mod(v*v));
                    t2 = mod(t2-mod(x*mod(A[x]*A[x])) + mod(x*mod(v*v)));
                    ll sm_ = mod(sm-A[x] + v);
                    c = mod(c-mod(sm*A[x])+ sm_*v);
                    sm = sm_;
                    A[x] = v;
                    break;
                }
                case 2:{
                    ll x,v;
                    cin >> x >> v;
                    v = A[x] + v;
                    t1 = mod(t1-mod((n-x+1)*mod(A[x]*A[x]))+mod(n-x+1)*mod(v*v));
                    t2 = mod(t2-mod(x*mod(A[x]*A[x])) + mod(x*mod(v*v)));
                    ll sm_ = mod(sm-A[x] + v);
                    c = mod(c-mod(sm*A[x])+ sm_*v);
                    sm = sm_;
                    A[x] = v;
                    break;
                }
                case 3:{
                    ll fx = mod(t1+t2-mod(2*c));
                    put(fx)
                    break;
                }
            }
        }
        
    }

    return 0;
}
