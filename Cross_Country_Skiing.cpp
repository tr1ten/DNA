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
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define tkv(vec,sz) FOR(i,0,sz) cin>>vec[i]
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
const int N = 1005;
ll mat[N][N];
bool vis[N][N];
bool check[N][N];
int n,m;
int total;

ll flood_fill(int i,int j,ll diff){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    vis[i][j]=1;
    ll cun = 0;
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    while (!q.empty())
    {   
        auto p = q.front();
        cun += check[p.first][p.second];
        // debug("visiting ",cun,p,diff,check[p.first][p.second]);
        q.pop();
        for(int k=0;k<4;k++){
            int y =p.first+dy[k],x=p.second+dx[k];
            if(x<m && y <n && x>=0 && y>=0 && !vis[y][x] && abs(mat[y][x]-mat[p.first][p.second])  <= diff) {
                vis[y][x] =1;
                q.push(make_pair(y,x));
            }
        }
    }
    return cun;
    
}
bool ok(ll x){
    ll cnt = 0;
    memset(vis,0,sizeof vis);
    int f = 0;
    rep(i,0,n){
        rep(j,0,m){
            if(check[i][j]){cnt = flood_fill(i,j,x);f=1; break;}
        }
        if(f) break;

    }
    return cnt>=total;
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
        cin >> n >> m;
        rep(i,0,n){
            rep(j,0,m) cin >> mat[i][j];
        }
        rep(i,0,n){
            rep(j,0,m) {cin >> check[i][j];total+=check[i][j]; }
            
        }
        ll lo = 0,hi =1000;
        ll ans=1e10;
        while(lo<=hi){
            ll mid = (lo+hi)/2;
            if(ok(mid)){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
            // debug(mid,lo,hi);
        }
        put(ans);
    }

    return 0;
}
