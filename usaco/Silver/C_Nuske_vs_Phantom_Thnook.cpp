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

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        int n,m,q;
        cin >> n >> m >> q;
        mk_mat(mat,n+1,m+1,0);
        mk_mat(pref,n+1,m+1,0);
        mk_mat(vers,n+1,m+1,0);
        mk_mat(hors,n+1,m+1,0);
        rep(i,0,n){
            string s ;
            cin >> s;
            rep(j,0,m){
                mat[i][j] = (s[j]=='1');
            }
        }
        per(i,0,n){
            per(j,0,m){
                pref[i][j] = mat[i][j] + pref[i+1][j] + pref[i][j+1] - pref[i+1][j+1];
                hors[i][j] = (mat[i][j] && mat[i][j]==mat[i][j+1]) + hors[i+1][j] + hors[i][j+1] - hors[i+1][j+1];
                vers[i][j] = (mat[i][j] && mat[i][j]==mat[i+1][j]) + vers[i+1][j] + vers[i][j+1] - vers[i+1][j+1];
            }
        }
        auto gs = [&](int r1,int c1,int r2,int c2, vii &ps){
            return  ps[r1][c1]-(ps[r1][c2+1] + ps[r2+1][c1]) + ps[r2+1][c2+1];
        };
        rep(i,0,q){
            int r1,r2,c1,c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;c1--;r2--;c2--;
            ll res = gs(r1,c1,r2,c2,pref)-gs(r1,c1,r2,c2-1,hors)-gs(r1,c1,r2-1,c2,vers);
            put(res);
        }
    }

    return 0;
}
