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

vi D;
int n;
ll L;
vii shows; 
vector<vector<vector<int>>> nxt_show;
void preprocess(){
    nxt_show.resize(n);
    rep(i,0,n){
        nxt_show[i].resize(n);
        rep(j,0,n){
            if(i==j) continue;
            nxt_show[i][j].resize(shows[i].size(),-1);
            rep(ii,0,shows[i].size()){
                auto it = upper_bound(all(shows[j]),shows[i][ii]+D[i]);
                if(it==shows[j].begin()) nxt_show[i][j][ii] = -1;
                else {
                    it--;
                    if((*it)+D[j]< shows[i][ii]+D[i] || (*it) > shows[i][ii]+D[i]) nxt_show[i][j][ii] = -1;
                    else nxt_show[i][j][ii] = it-shows[j].begin();
                }
            }
        }
    }
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("movie.in","r",stdin);
    freopen("movie.out","w",stdout);	  
    int T=1;
    // cin>>T;
    while(T--){
        cin >> n >> L;
        D.resize(n);
        shows.resize(n);
        rep(i,0,n){
            cin >> D[i];
            int sz;
            cin >> sz;
            rep(j,0,sz) {
                ll x;
                cin >> x;
                shows[i].push_back(x);
            }
        }
        preprocess();
        vpi dp; // dp[i] -> last watched show time
        dp.resize(1<<n,mp(-1,-1));
        dp[0] = {0,0};
        auto cmp = [&](pi &p1,pi &p2){
            return shows[p1.first][p1.second] + D[p1.first] < shows[p2.first][p2.second] + D[p2.first];
        };
        int ans = n+1;
        rep(mask,0,1<<n){
            if(dp[mask].first==-1) continue;
            rep(i,0,n){
                if(mask&(1<<i)) continue;
                int nxt = mask | (1<<i);
                int sj = -1;
                if(mask == 0){
                    if(shows[i][0]==0) sj = 0;
                }
                else sj = nxt_show[dp[mask].first][i][dp[mask].second];
                if(sj==-1) continue;
                pi val = {i,sj};
                if( dp[nxt].first==-1 || cmp(dp[nxt],val)) dp[nxt] =val;
                if(shows[dp[nxt].first][dp[nxt].second] + D[dp[nxt].first] >=L) {
                    ans =min(__builtin_popcount(nxt),ans);
                    
                    }
            }
        }
        if(ans==n+1) put(-1)
        else put(ans);

    }

    return 0;
}