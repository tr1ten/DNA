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
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL,LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL,LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define rep(N) FOR(i,0,N)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
#define vec_sum(vec) accumulate(vec.begin(), vec.end(), 0L);
#define vec_max(vec) *max_element(vec.begin(), vec.end());
#define vec_min(vec) *min_element(vec.begin(), vec.end());
#define put_vec(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define put(x) cout<<(x)<<endl;
#define put2(x,y) cout<<(x)<<" "<<(y)<<endl;
#define put3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl;
#define take(x) cin >> x;
#define take2(x,y) cin >> x >> y;
#define take3(x,y,z) cin >> x >> y >> z;

#define timed(x) {auto start = chrono::steady_clock::now(); x; auto end = chrono::steady_clock::now(); auto diff = end - start; cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;}

const LL MOD = 1e9+7;
const LL INF = 1e10+5;



// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        LL k;
        take3(n,m,k);
        mk_mat(mat,n,m,0);
        FOR(i,0,n){
            FOR(j,0,m) cin >> mat[i][j];
        }
        mk_mat(pref,n+1,m+1,0);
        ROF(i,0,n){
            ROF(j,0,m){
                pref[i][j] = mat[i][j] + pref[i+1][j] + pref[i][j+1] - pref[i+1][j+1];
            }
        }
        if(pref[0][0]<k+1) {put("-1");continue;}
        auto get = [&](int j1,int i1,int j2,int i2){
            return pref[i1][j1]+pref[i2+1][j2+1]-pref[i1][j2+1]-pref[i2+1][j1];
        };
        auto ok = [&](int mid){
            FOR(i,0,n){
                FOR(j,0,m){
                    if(!mat[i][j]) continue;
                    int y1=max(i-mid,0),y2=min(i+mid,n-1);
                    int x1=max(j-mid,0),x2=min(j+mid,m-1);
                    if(get(x1,y1,x2,y2)>=k+1) return true;
                }
            }
            return false;
        };
        LL lo =0,hi = max(n,m);
        while(lo<hi){
            int d = lo + (hi-lo)/2;
            if(ok(d)) hi = d;
            else lo = d+1;
        }
        put(lo)
    }

    return 0;
}
