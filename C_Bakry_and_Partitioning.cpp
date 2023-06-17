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
const int MAX= 1e5+5;
int dep[MAX];
int par[MAX];
ll dfs(int u,int p,int d,vii &adj,vi &a,vi &xors){
    ll res = a[u];
    par[u] = p;
    dep[u] = d+1;
    trav(v,adj[u]){
        if(v==p) continue;
        res ^= dfs(v,u,d+1,adj,a,xors);
    }
    xors[u] = res;
    return res;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin >> n >> k;
        vi a(n);
        tkv(a,n);
        vii adj(n);
        rep(i,0,n-1){
            int u,v;
            cin >> u >> v;
            u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // atleast 1 and atmost k-1 edges to remove 
        // make all component have same xor
        // if ans is yes then we can have the follwing cases
        // let suppose we delete odd edges then we have even components
        // these same xor then that implies xor of whole tree should be 0
        // need to check if 

        // case 2: if we delete even number of edges (k>2),
        // then xor of whole tree will have same value as its component
        // so we have to check if there exist atleast one component having that xor

        // are above condition sufficient for it be true? i
        // let assume its true ;)
        // 1-2-3 , 3-3-1 = 1
        // 3-3-1|-3-1-3  = 1 might fail we only get xor=1 at one palce
        //   \| 1
        // 3-3-1
        vi xors(n,-1);
        dfs(0,-1,0,adj,a,xors);
        if(xors[0]==0) put("YES")
        else{
            if(k<=2) {put("NO"); continue;}
            ll tar = xors[0];
            int fi = -1;
            rep(i,1,n){
                if((xors[i]^tar)==0 && (fi==-1 || dep[fi]<dep[i])) {
                    fi = i;
                }
            }
            if(fi==-1) {put("NO"); continue;}

            adj[par[fi]].erase(find(all(adj[par[fi]]),fi));
            adj[fi].erase(find(all(adj[fi]),par[fi]));
            xors.clear();
            xors.assign(n,-1);
            bool flag =0;
            dfs(0,-1,0,adj,a,xors);
            // tar = xors[0];
            rep(i,1,n){
                if((xors[i]^tar)==0) {
                    flag = 1;
                    break;
                }
            }
            if(flag) put("YES") // atkeast two component having xor tatr
            else {
                put("NO");
            }
        }
        

    }

    return 0;
}


// 2\ / 9 - 1
// 7-3-4
//    6-\4-5
//    \8
//
//