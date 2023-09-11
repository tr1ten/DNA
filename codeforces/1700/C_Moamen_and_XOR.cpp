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
#define rep(i,a,b) for (ll i = (a); i < (b); i++)
#define per(i,a,b) for (ll i = (b)-1; i >= (a); i--)
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
#define mod(x) ((x + MOD)%MOD)
// debugging
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}


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
void __print(const T &x) {ll f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
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
const ll K = 2*(1e5) + 5;

ll mpow(ll a, ll b, ll m)
{
    if (b == 0)
        return 1;
    ll x = mpow(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2)
    {
        x = (x * a) % m;
    }
    return x;
}



// driver code
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //    for(ll i = 2 ; i < sz ; i++){
    //        if(primesVisited[i]) continue;
    //        primes.pb(i);
    //        for(ll j = i*i ; j < sz ; j+=i) primesVisited[j] = true;
    //    }

     ll mod =1000000007;
     ll tc;
     cin >> tc;
     while(tc--){
        ll n,k;
        cin >> n >> k;
        if(k == 0) cout << 1 << endl;
        if(k == 0) continue;

        vector<int> dp(k+1,0);

        for(ll bit =0 ; bit < k ; bit++){
            if(bit == 0){
                ll waysToWin = 0;
                if(n%2 == 0){
                    waysToWin = (mpow(2,n-1,mod))%mod;
                }else{
                    waysToWin = (1 + mpow(2,n-1,mod))%mod;
                }
                dp[bit] = waysToWin;
                continue;
            }

            ll waysToWin = 0;

            if(n%2 == 0){
                waysToWin += mpow(2,((bit*n)),mod);
                ll temp = (((mpow(2,n-1,mod)-1+mod)%mod)*dp[bit-1])%mod;
                waysToWin = (waysToWin + temp)%mod;
            }else{
                waysToWin += dp[bit-1];
                ll temp = (mpow(2,n-1,mod)*dp[bit-1])%mod;
                waysToWin = (waysToWin + temp)%mod;
            }

            dp[bit] = waysToWin;
        }
        cout << dp[k-1] << endl;
     }

}