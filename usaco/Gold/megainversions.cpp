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
typedef long long ll;
const int N = 2*(1e5) + 5;
struct Segment{
    ll sum,lazy;
} segm[2*N]; // 0 index


void propogate(int node,int left,int right){
    segm[node].sum += (right-left+1)*segm[node].lazy;
    if(left<right){
        segm[2*node+1].lazy += segm[node].lazy;
        segm[2*node+2].lazy += segm[node].lazy;
    }
    segm[node].lazy =0;
    
}
// child- 2*x+1,2*x+2 (0 coz index)
// add x to [l...r]
void update(int node,int left,int right,int l,int r,ll value){
    propogate(node,left,right); // main funda update only when called
    if(left>=l && right<=r) {
        segm[node].lazy += value;
        }
    else{
        int mid = (left+right)/2;
        if(l<=mid) update(2*node+1,left,mid,l,r,value);
        if(r>mid) update(2*node+2,mid+1,right,l,r,value);
        propogate(2*node+1,left,mid); // since we need to use thier value they must be updated
        propogate(2*node+2,mid+1,right);
        segm[node].sum = segm[2*node+1].sum + segm[2*node+2].sum;

    }
    
}

ll query(int node,int left,int right,int l,int r){
    propogate(node,left,right);
    if(left>=l && right<=r) return segm[node].sum;
    int mid = (left+right)/2;
    ll res= 0;
    if(l<=mid) res +=query(2*node+1,left,mid,l,r);
    if(r>mid) res +=query(2*node+2,mid+1,right,l,r);
    return res;

}
// everything is zero indexed
void update(int l,int r,ll x,int n){
    update(0,0,n-1,l,r,x);
}
ll query(int l,int r,int n){
    return query(0,0,n-1,l,r);
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);	  
    int T=1;
    // cin>>T
    while(T--){
        int n;
        cin >> n;
        ordered_multiset<int> ms;
        ll res = 0;
        rep(i,0,n){
            int x;
            cin >> x;
            ms.insert(x);
            int iv = ms.size()-ms.order_of_key(x+1);
            res += query(x+1,n-1,n);
            update(x,x,iv,n);
        }
        put(res);
    }

    return 0;
}
