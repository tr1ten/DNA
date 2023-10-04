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
#define puts(x) cout << (x) << " ";
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
struct  pr {
    int x;
    int y;
    int steps;
    ll cost;
};

struct cmp {

	bool operator()(const pr &x, const pr &y) const { 
        return x.cost > y.cost;
    }
};

int n,m,k;
// TLE
// ll bfs(int i,int j,vii &cc,vii &rc){
//     priority_queue<pr,vector<pr>,cmp> pq;
//     pq.push({j,i,0,0});
    // int dx[4] = {-1,1,0,0};
    // int dy[4] = {0,0,-1,1};
//     unordered_map<int,unordered_map<int,unordered_map<int,ll>>> dist;
//     dist[i][j][0] = 0;
//     while (pq.size())
//     {
//         auto p = pq.top();
//         pq.pop();
//         if(dist[p.y][p.x].find(p.steps)!=dist[p.y][p.x].end() && dist[p.y][p.x][p.steps] < p.cost ) continue;
//         if(p.steps ==k){
//             if(p.x==j && p.y==i) return p.cost;
//             continue;
//         }
//         rep(d,0,4){
//             int y = p.y + dy[d];
//             int x = p.x + dx[d];
//             ll c= 0;

//             if(y>=0 && y<n && x>=0 && x<m && (abs(y-i) + abs(x-j))<=(k-(p.steps+1))  ) {
                // if(d==2) c = rc[y][x];
                // else if(d==3) c= rc[p.y][p.x];
                // else if(d==0) c = cc[y][x];
                // else c = cc[p.y][p.x];
//                 if(dist[y][x].find(p.steps+1)!=dist[y][x].end() && dist[y][x][p.steps+1]<=p.cost+c) continue;
//                 dist[y][x][p.steps+1] = p.cost + c;
//                 pq.push({x,y,p.steps+1,p.cost+c});
//             }
//         }
//     }
//     return -1;
    
// }
bool inside(int x,int y){
    return (y>=0 && y<n && x>=0 && x<m);
}
const int K = 20;
const int N = 505;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
ll dp[(K/2) + 5][N][N];
int cc[N][N];
int rc[N][N];
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
        cin >> n >> m >> k;
        rep(i,0,n){
            rep(j,0,m-1) cin >> cc[i][j];
        }
        rep(i,0,n-1){
            rep(j,0,m) cin >> rc[i][j];
        }
        bool BAD = k%2;
        memset(dp,-1,sizeof dp);
        if(!BAD){
            rep(i,0,n) {rep(j,0,m) dp[0][i][j]=0;}
            rep(d,0,(k/2)){
                rep(i,0,n){
                    rep(j,0,m){
                        rep(c,0,4){
                            int x = j+dx[c];
                            int y= i+dy[c];
                            if(inside(x,y)){
                                ll cs = 0;
                                if(c==2) cs = rc[y][x];
                                else if(c==3) cs= rc[i][j];
                                else if(c==0) cs = cc[y][x];
                                else cs = cc[i][j];
                                ll total = dp[d][i][j] + cs;
                                if(dp[d+1][y][x]==-1) dp[d+1][y][x] = total;
                                else dp[d+1][y][x] = min(total,dp[d+1][y][x]);
                            }
                        }
                    }
                }
            }
        }
        rep(i,0,n){
            rep(j,0,m){
                puts(max(-1ll,2*dp[k/2][i][j]));
            }
            cout << endl;
        }
    }

    return 0;
}
