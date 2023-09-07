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
int n,k,m;
vector<string> mat;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(int i,int j,vii &dist){ // 0/1 bfs
    dist[i][j] = mat[i][j]=='+';
    deque<pair<int,int>> pq;
    pq.push_back({i,j});
    while(!pq.empty()){
        auto p = pq.front();
        pq.pop_front();
        rep(k,0,4){
            int y = p.first+dy[k];
            int x = p.second + dx[k];
            if(y<0 || y>=n || x>=n || x<0 || mat[y][x]=='#' || dist[y][x]!=INF) continue;
            if(mat[y][x]=='.') {dist[y][x] = dist[p.first][p.second]; pq.push_front({y,x}); }
            else {dist[y][x] = dist[p.first][p.second] + 1; pq.push_back({y,x}); }
        }
    }
}

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
        cin >> n >> k >>m;
        mat.resize(n);
        vector<vii> dists(k+1,vii(n,vi(n,INF)));
        rep(i,0,n){
            cin >> mat[i];
        }
        // calcualate shortest distance from cells of interest 
        bfs(0,0,dists[k]);
        pair<ll,pi> foss[k];
        rep(i,0,k){
            cin >> foss[i].second.first >> foss[i].second.second >> foss[i].first;
            foss[i].second.second--;
            foss[i].second.first--;
            bfs(foss[i].second.first,foss[i].second.second,dists[i]);
        }
        // similar to TSP
        vii dp1(k,vi(1<<k,INF)); // dp[last][mask]: min cost to collect mask fossils ending at last (not considering return and max wt by wb)
        // base case 
        rep(i,0,k){
            dp1[i][1<<i] = dists[k][foss[i].second.first][foss[i].second.second];
        }
        rep(mask,0,1<<k){
            rep(last,0,k){
                if(!(mask&(1<<last))) continue;
                rep(to,0,k){
                    if(!(mask&(1<<to))){
                        dp1[to][mask | 1<<to] = min(dp1[to][mask | 1<<to],dp1[last][mask] + dists[last][foss[to].second.first][foss[to].second.second]);
                    }
                }
            }
        }
        vi dp2(1<<k,INF); // min cost to collect mask fossils and return before wt exceeds capacity
        dp2[0] = 0;
        rep(mask,0,1<<k){
            // find total wt of foss
            ll total = 0;
            rep(i,0,k){
                if(mask&(1<<i)) total+= foss[i].first; 
            }
            if(total<=m) {
                rep(last,0,k){
                    dp2[mask] = min(dp2[mask],dp1[last][mask] + dists[k][foss[last].second.first][foss[last].second.second]);
                }
            }
            else{ // try to devide mask into two submask to find ans 
                for(ll sub=mask;;sub=(sub-1)&(mask)){
                    dp2[mask] = min(dp2[mask],dp2[sub]+ dp2[sub^mask]);
                    if(sub==0) break;
                }
            }
        }
        put(dp2[(1<<k)-1]);
        

    }

    return 0;
}
