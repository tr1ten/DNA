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
const int N = 105;
bool vis[N][N];
bool check[N][N];
bool ban[N][N][N][N];
int n, m;
int i_min, i_max, j_min, j_max;
ll flood_fill(int i, int j)
{
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    vis[i][j] = 1;
    ll cun = 0;
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    while (!q.empty())
    {
        auto p = q.front();
        cun += check[p.first][p.second];
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int y = p.first + dy[k], x = p.second + dx[k];
            if (x <= j_max && y <= i_max && x >= j_min && y >= i_min && !vis[y][x] && !ban[p.first][p.second][y][x])
            {
                vis[y][x] = 1;
                q.push(make_pair(y, x));
            }
        }
    }
    return cun;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("countcross.in","r",stdin);
    freopen("countcross.out","w",stdout);	  
    int T=1;
    // cin>>T;
    while(T--){
        int n,k,r;
        cin >> n >> k >> r;
        i_min = 0;j_min=0;i_max=n-1;j_max=n-1;
        rep(i,0,r){
            int r1,c1,r2,c2;
            cin >> r1>>c1>>r2>> c2;
            r1--;r2--;c1--;c2--;
            ban[r1][c1][r2][c2]=1;
            ban[r2][c2][r1][c1]=1;
        }
        rep(i,0,k){
            int r,c;
            cin >> r >> c;
            r--;c--;
            check[r][c]=1;
        }
        vi cmpts;
        rep(i,0,n){
            rep(j,0,n){
                if(!vis[i][j]){
                    int area = flood_fill(i,j);
                    cmpts.push_back(area);
                }
            }
        }
        ll res = 0;
        rep(i,0,cmpts.size()){
            rep(j,i+1,cmpts.size()){
                res += cmpts[i]*cmpts[j];
            }
        }
        put(res);
        
    }

    return 0;
}
