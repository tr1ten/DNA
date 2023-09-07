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

const ll B = 9973;
const ll mod = MOD;
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cownomics.in","r",stdin);
    freopen("cownomics.out","w",stdout);	  
    int T=1;
    // cin>>T;
    while(T--){
        int n,m;
        cin >> n >> m;
        vector<string> sp(n);
        vector<string> nrm(n);
        rep(i,0,n) cin >> sp[i];
        rep(i,0,n) cin >> nrm[i];
        int ans = -1;
        int lo=1,hi=m;
        vi pp{1};
        rep(i,1,m+1){
            pp.push_back(pp.back()*B%mod);
        }
        auto ok = [&] (int len){
            ll p = 1;
            vi hash(n,0);
            vi hash2(n,0);
            int pos = 0;
            rep(i,0,m){
                unordered_set<ll> hs;
                int f = 1;
                rep(j,0,n){
                    if(i<=len-1) hash[j] = mod(mod(hash[j]*B) + (nrm[j][i]));
                    else{
                        hash[j] = mod(mod(mod(hash[j] - mod((nrm[j][i-len] - 'a')*pp[len-1]))*B) + (nrm[j][i]-'a'));
                    } 
                    if(i>=len-1) hs.insert(hash[j]);
                }
                rep(j,0,n){
                    if(i<=len-1)   hash2[j] = mod(mod(hash2[j]*B) + (sp[j][i]));
                    else{
                        hash2[j] = mod(mod(mod(hash2[j] - mod((sp[j][i-len] - 'a')*pp[len-1]))*B) + (sp[j][i]-'a'));
                    } 
                    if(i>=len-1 && hs.find(hash2[j])!=hs.end() ) f=0;
                }
                if(i>=len-1 && f){return 1;}
            }
            return 0;
        };
        while (lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(ok(mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        put(ans);

        
    }

    return 0;
}
