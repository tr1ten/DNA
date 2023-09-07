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
const int N = 256;  // limit for array size
int n;  // array size, near power of two
int t[2 * N]; // 0 index
// iterative segment tree

int combine(int left,int right){return max(left,right);}
void build() {  // build the tree; fill from last secnod layer
    for (int i = n - 1; i > 0; --i) t[i] = combine(t[i<<1], t[i<<1|1]);
}


void update(int p, const int value) {
  for (t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

int query(int l, int r) { // [l,r) important
  int resl=0, resr=0;
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) resl = combine(resl, t[l++]); // l&1 mean l is right child, parent not included so shift to parent right
    if (r&1) resr = combine(t[--r], resr); // 
  }
  return combine(resl, resr);
}

void init(int nn){
    n = nn;
    memset(t,0,sizeof t);
  for (int i = 0; i < n; ++i) t[n + i]=0;
  build();
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fortmoo.in","r",stdin);
    freopen("fortmoo.out","w",stdout);	  
    int T=1;
    while(T--){
        int n,m;
        cin >> n >> m;
        int mat[n+1][m+1];
        rep(i,0,n){
            rep(j,0,m){
                char x;
                cin >> x;
                mat[i][j] = (x=='.');
            }
        }
        int dp[n+1][m+1][2];
        memset(dp,0,sizeof dp);
        int ans = 0;
        rep(i,0,n){
            rep(j,0,m){
                if(mat[i][j]) {dp[i][j][0] = (j-1>=0 ? dp[i][j-1][0] : 0)+1;dp[i][j][1] =(i-1>=0 ? dp[i-1][j][1] : 0)+1;}
                else continue;
                vector<pair<int,int>> xs;
                per(k,0,j){
                    if(mat[i][k]==0) break;
                    int mxh = dp[i][k][1];
                    xs.push_back({mxh, j-k+1});
                }
                srv(xs);
                init(N);
                int lmt = dp[i][j][1]+1;
                int h = 1;
                rep(k,0,xs.size()){
                    auto pp = xs[k];
                    while(h<=pp.first && h<lmt)
                    {
                        int k = i-h+1;
                        int mxw = dp[k][j][0];
                        update(mxw,h);
                        // debug(query(mxw,N),h);
                        assert(query(mxw,N)>=h);
                        h++;
                    }
                    int mxh = query(pp.second,N);
                    ans = max(ans,mxh*pp.second);

                }
                
            }
        }
        put(ans);
    }

    return 0;
}
