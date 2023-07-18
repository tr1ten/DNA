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
vi amt; // pre cal cost of each mask
vi A;
vi B;
inline int pct(int x){ return __builtin_popcount(x);}
// void rec(vector<int> &nt,int idx,int t_mask,int mask,int target,int *dp){
//     if(idx==(int)nt.size()) {
        // int ans = dp[mask] | 1<<target;
        // if(amt[t_mask] == A[target] && pct(dp[mask | t_mask]) < pct(ans)) {
        //     dp[mask | t_mask] = ans;
            
        // }
        // return;
//     }
//     rec(nt,idx+1,t_mask,mask,target,dp);
//     if(A[target] - amt[t_mask | 1<<nt[idx]] >=0) rec(nt,idx+1,t_mask | 1<<nt[idx],mask,target,dp);
// }

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);	  
    int T=1;
    // cin>>T;
    while(T--){
        int n,m;
        cin >> n >> m;
        int M = 1<<m;
        A.resize(n);
        tkv(A,n);
        B.resize(m);
        tkv(B,m);
        int dp[1<<m]; // max pref of people it can give slary 
        int left[1<<m]; // amt left 
        memset(dp,-1,sizeof dp);
        memset(left,-1,sizeof left);
        dp[0] = 0;
        left[0] = 0;
        bool f= 0;
        rep(mask,0,M){
            rep(j,0,m){
                if(mask&(1<<j)==0) continue;
                int prev = mask  ^ (1<<j);
                if(dp[prev]==-1) continue;
                int na = left[prev] + B[j];
                if(na<A[dp[prev]]) {
                    dp[mask] = dp[prev];
                    left[mask] = na;
                }
                else if(na==A[dp[prev]]){
                    dp[mask] = dp[prev] + 1;
                    left[mask] = 0;
                }
            }
            if(dp[mask]==n) {f = 1;break;}
        }
        if(f) put("YES")
        else put("NO")
    }

    return 0;
}