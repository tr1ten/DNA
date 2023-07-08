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
const ll INF = 1e9+5;

class DSU
{
public:
    int *par;
    int *sz;
    DSU(int n)
    {
        this->par = new int[n];
        this->sz = new int[n];
        for (int i = 0; i < n; i++)
        {
            this->par[i] = i;
            this->sz[i] = 1;
        }
    }
    int find(int x)
    {
        int p = x;
        while (p != this->par[p])
        {
            p = par[p];
        }
        return p;
    }
    void unionn(int u, int v)
    {
        int rootu = find(u);
        int rootv = find(v);
        if (rootu == rootv)
            return;
        if (sz[rootu] < sz[rootv])
        {
            par[rootu] = rootv;
            sz[rootv] += sz[rootu];
        }
        else
        {
            par[rootv] = rootu;
            sz[rootu] += sz[rootv];
        }
    }
};


struct Rect{
    int x1=INF;
    int y1=INF;
    int x2=-INF;
    int y2=-INF;
    int peri(){
        return 2*(x2-x1) + 2*(y2-y1);
    }
};
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    
    int T=1;
    // cin>>T;
    while(T--){
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>> vip;
        rep(i,0,n){
            int x,y;
            cin >> x >> y;
            vip.push_back(mp(x,y));
        }
        DSU ds(n);
        rep(i,0,m){
            int u,v;
            cin >> u >> v;
            u--;v--;
            ds.unionn(u,v);
        }
        unordered_map<int,Rect> cmpts;
        rep(i,0,n){
            int x = ds.find(i);
            cmpts[x].x1 = min(vip[i].first,cmpts[x].x1);
            cmpts[x].x2 = max(vip[i].first,cmpts[x].x2);
            cmpts[x].y1 = min(vip[i].second,cmpts[x].y1);
            cmpts[x].y2 = max(vip[i].second,cmpts[x].y2);
        }
        int res = INF;
        trav(x,cmpts){
            res = min(res,x.second.peri());
        }
        put(res);
    }

    return 0;
}

