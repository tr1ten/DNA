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
// const int MAXN = 1000 + 5;
// LL mem[MAXN][MAXN][2];
VI A;
VI B;
// LL dp(int i,int j,bool took){
//     if(i>j) return 0;
//     if(i==j) return A[i]*B[i];
//     // if(mem[i][j][took]!=-1) return mem[i][j][took];
//     mem[i][j][took] = max(mem[i][j][took],dp(i+1,j-1,1)  + A[j]*B[i] + A[i]*B[j]);
//     if(!took){
//         mem[i][j][took] = max(mem[i][j][took],dp(i+1,j,0)  + A[i]*B[i] );
//         mem[i][j][took] = max(mem[i][j][took],dp(i,j-1,0)  + A[j]*B[j] );
//     }
//     return mem[i][j][took];
// }

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T=1;
    // cin>>T;
    while(T--){
        int n;
        take(n);
        A.assign(n,0);
        B.assign(n,0);
        take_vec(A,n);
        take_vec(B,n);
        LL S = 0;
        FOR(i,0,n) S+= A[i]*B[i];
        LL res = S;
        FOR(i,0,n){
            int z=0;
            LL s = 0;
            while(i-z>=0 && i+z<n){
                s += (B[i+z]-B[i-z])*(A[i-z]-A[i+z]);
                res = max(res,S+s);
                z++;
            }
            s = 0;
            z = 0;
            while(i-z>=0 && i+z+1<n){
                s += (B[i+z+1]-B[i-z])*(A[i-z]-A[i+z+1]);
                res = max(res,S+s);
                z++;
            }
        }
        put(res);
    }

    return 0;
}
