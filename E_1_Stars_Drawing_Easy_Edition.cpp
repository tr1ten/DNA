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
#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}
void __print(auto x) {cerr << x;}
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; __print(x); cerr << endl;
#else
#define debug(x)
#endif
const ll MOD = 1e9+7;
const ll INF = 1e10+5;
const int N=105;
int mat[N][N];
int draw(int i,int j,int sz){
    int a=0,b=0,c=0,d=0;
    int cnt = 0;
    while(a<sz) {cnt+=(mat[i+a][j]==1);mat[i+a][j]=2;a++;}
    while(b<sz) {cnt+=(mat[i-b][j]==1);mat[i-b][j]=2;b++;}
    while(c<sz) {cnt+=(mat[i][j+c]==1);mat[i][j+c]=2;c++;}
    while(d<sz) {cnt+=(mat[i][j-d]==1);mat[i][j-d]=2;d++;}
    return cnt;
}
struct Star{
    int y;
    int x;
    int sz;
};
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        int n,m;
        cin >> n >> m;
        int total = 0;
        rep(i,0,n){
            rep(j,0,m){
                char x;
                cin >> x;
                if(x=='*') {mat[i][j] = 1;total++;}
                else mat[i][j] = 0;
            }
        }
        vector<Star> stars;
        rep(i,0,n){
            rep(j,0,m){
                if(!mat[i][j]) continue;
                int a=0,b=0,c=0,d=0;
                while(i+a<n && mat[i+a][j]) a++;
                while(i-b>=0 && mat[i-b][j]) b++;
                while(j+c<m && mat[i][j+c]) c++;
                while(j-d>=0 && mat[i][j-d]) d++;
                int sz = min(a,min(b,min(c,d)));
                if(sz<=1) continue;
                int nw = draw(i,j,sz);
                if(nw){
                    stars.push_back({i,j,sz-1});
                    total -=nw;
                }

            }
        }
        if(total>0) {put(-1);continue;}
        put(stars.size()) 
        trav(s,stars){
            put3(s.y+1,s.x+1,s.sz);
        }
    }

    return 0;
}
