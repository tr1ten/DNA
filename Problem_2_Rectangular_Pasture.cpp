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
void update(int BIT[],int x,int val,int N) { ++x;  while(x<=N)  {  BIT[x]+=val;BIT[x] %=MOD; x+=(x&-x);  } }
ll query(int BIT[],int x) {  ++x;  ll res=0;  while(x>0)  {  res+=BIT[x];res%=MOD;  x-=(x&-x);  } return res; } 
ll range(int bit[],int a,int b){ return (query(bit,b) - query(bit,a-1) + MOD)%MOD;}

ll fast_pow(ll a,ll b,ll MOD){
    if(b==0) return 1;
    if(b==1) return a;
    ll res = fast_pow(a,b/2,MOD);
    if(b%2==0) return (res*res)%MOD;
    return (((res*res)%MOD)*a)%MOD;
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        int n;
        cin >> n;
        vpi pts;
        map<int,int> cnt;
        rep(i,0,n) {
            int x,y;
            cin >> x >> y;
            pts.push_back(mp(x,y));
            cnt[y]++;
        }
        unordered_map<int,int> yid;
        int id = 0;
        trav(y,cnt){
            yid[y.first] = id++;
        }
        srv(pts);
        ll ex=0;
        rep(i,0,n){
            int bit[id+1];
            memset(bit,0,sizeof bit);
            ll ins = 0;
            update(bit,yid[pts[i].second],1,id);
            rep(j,i+1,n){
                update(bit,yid[pts[j].second],1,id);
                int y1 = yid[pts[i].second];
                int y2 = yid[pts[j].second];
                ins += range(bit,min(y1,y2),max(y1,y2))-2;
            }
            
        }


    }

    return 0;
}
