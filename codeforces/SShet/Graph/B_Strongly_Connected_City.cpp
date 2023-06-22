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

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 +5;
vector<int> ids;
vector<int> low;
bool onStack[N];
stack<int> st;
vector<vector<int>> g;
int timer;
int scc_count;
void dfs(int u){
    onStack[u] = 1;
    st.push(u);
    ids[u] = low[u] = timer++;
    for(int v:g[u]){
        if(ids[v]==-1) dfs(v);
        if(onStack[v]) low[u] = min(low[u],low[v]); // maintain stack invariant, only include node in scc
    }
    if(low[u]==ids[u]){
        while(!st.empty()) {
            int v = st.top();
            onStack[v] = 0;
            low[v] = low[u];// once scc completed, reset back to start
            st.pop();
            if(v==u) break;
        } 
        scc_count++;
    }
}
int stronglyConnectedComponents(int n, vector<vector<int>> &adj)
{
    timer=0;
    scc_count = 0;
    ids.resize(n);
    fill(ids.begin(),ids.end(),-1);
    low.resize(n);
    g=adj;
    for(int i=0;i<n;i++){
        if(ids[i]==-1){
            dfs(i);
        }
    }
    return scc_count;
}
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
        string hors;
        string vers;
        cin >> hors;
        cin >> vers;
        vector<vector<int>> adj(n*m);
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        char dir[] = {'^','v','<','>'};
        rep(i,0,n){
            rep(j,0,m){
                rep(k,0,4){
                    int y=i+dy[k];
                    int x=j+dx[k];
                    if(y<n && y>=0 && x<m && x>=0){
                        if(hors[y]!=dir[k] && vers[x]!=dir[k]) continue;
                        adj[i*m + j].push_back(y*m + x);
                    }
                }
            }
        }
        int sc = stronglyConnectedComponents(n*m,adj);
        if(sc==1) put("YES")
        else put("NO")
    }

    return 0;
}
