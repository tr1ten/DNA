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
typedef int ll; 
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
#define mod(x) (x + MOD)%MOD
// debugging


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
const int N = 200;
int pref[N+1][N+1];
int mat[N+1][N+1];
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);	
    int T=1;
    // cin>>T;
    while(T--){
        int n,K;
        cin >> n >> K;
        memset(pref,0,sizeof pref);
        memset(mat,0,sizeof mat);
        rep(i,0,n){
            int x1,y1,x2,y2;
            cin >>x1>>y1>>x2>>y2;
            pref[y1][x1]++;
            pref[y1][x2]--;
            pref[y2][x1]--;
            pref[y2][x2]++;
        }
        ll area = 0;
        
        rep(i,0,N){
            rep(j,0,N){
                if(i-1>=0) pref[i][j] +=pref[i-1][j];
                if(j-1>=0) pref[i][j] +=pref[i][j-1];
                if(i-1>=0 && j-1>=0) pref[i][j] -= pref[i-1][j-1];
                area += (pref[i][j]==K);
                if((pref[i][j]==K)) mat[i][j] -=1; // will lost one cell if repainted k+1 coat
                if((pref[i][j]==K-1)) mat[i][j] +=1; // can make optimal via one coat

            }
        }
        // now choose two submatrix with max sum
        ll mx = 0;
        auto gs = [&](int r1,int c1,int r2,int c2, int ps[][N+1]){
            return  ps[r1][c1]-(ps[r1][c2+1] + ps[r2+1][c1]) + ps[r2+1][c2+1];
        }; 
        per(i,0,N){
            per(j,0,N){
                mat[i][j] +=  mat[i+1][j] + mat[i][j+1] - mat[i+1][j+1];
            }
        }
        vi bottom(N+1);
        vi top(N+1);
        vi left(N+1);
        vi right(N+1);
        // draw a line hori and veri split into 4 regions
        // 2d prefix, think submatrices sum btw i...j as subarray then use kadane
        rep(i,0,N){
            rep(j,i,N){
                int btm=0,topsm=0;
                rep(r,0,N){
                    int v1 = gs(r,i,r,j,mat);
                    int v2 = gs(N-r-1,i,N-r-1,j,mat);
                    topsm = max(v1+topsm,0);
                    btm = max(v2+btm,0);
                    top[r] = max(top[r],topsm);
                    if(r-1>=0) top[r] = max(top[r],top[r-1]);
                    bottom[N-r-1] = max(bottom[N-r-1],btm);
                    bottom[N-r-1] = max(bottom[N-r],bottom[N-r-1]);
                }
                int lf=0,rf=0;
                rep(c,0,N){
                    int v1 = gs(i,c,j,c,mat);
                    int v2 = gs(i,N-c-1,j,N-c-1,mat);
                    lf = max(v1+lf,0);
                    rf = max(v2+rf,0);
                    left[c] = max(left[c],lf);
                    if(c-1>=0) left[c] = max(left[c],left[c-1]);
                    right[N-c-1] = max(right[N-c-1],rf);
                    right[N-c-1] = max(right[N-c],right[N-c-1]);

                }
                
            }
        }
        // debug(bottom,top,left,right);
        rep(i,0,N){
            mx = max(top[i]+bottom[i+1],mx);
            mx = max(left[i]+right[i+1],mx);
        }
        put(area+mx);
    }

    return 0;
}
