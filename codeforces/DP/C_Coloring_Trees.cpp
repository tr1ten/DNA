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
const ll INF = 1e17;
const int N=103;
ll dp[N][N][N];
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        int n,m,k;
        cin >> n >> m >> k;
        vi clr(n);
        tkv(clr,n);
        mk_mat(cost,n,m,0);
        
        rep(i,0,n){
            rep(j,0,m){
                cin >> cost[i][j];
            }
        }
        rep(i,0,n+1){
            rep(l,0,k+1){
                rep(j,0,m+1){
                    dp[i][l][j] = i==0 && l==0 ? 0 : INF;
                }
            }
        }
        rep(i,1,n+1){
            rep(j,1,k+1){
                if(clr[i-1]!=0){
                    ll res=  INF;
                    rep(c,i-1==0 ? 0 : 1,m+1){
                        res = min(res,(ll)dp[i-1][j-(c!=clr[i-1])][c]);
                    }
                    dp[i][j][clr[i-1]] = res;
                    continue;
                }
                rep(c,1,m+1){
                    ll res = INF;
                    rep(p,i-1==0 ? 0 : 1,m+1){
                        res = min(res,(ll)dp[i-1][j-(c!=p)][p] + cost[i-1][c-1]);
                    }
                    dp[i][j][c] = res;
                }
            }
        }
        ll res= INF;
        rep(i,1,m+1){
            res = min(res,(ll)dp[n][k][i]);
        }
        if(res>=INF) put(-1)
        else put(res);
    }

    return 0;
}
