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

priority_queue<int> lpq; // max heap
priority_queue<int,vector<int>,greater<int>> rpq; // min heap
ll lsum =0,rsum = 0;
void balance(){
    while(lpq.size()<rpq.size()){
        lpq.push(rpq.top());
        lsum +=rpq.top();
        rsum -=rpq.top();
        rpq.pop();
    }
}
void insert(int x){
    lpq.push(x);
    lsum +=x;
    lsum -=(lpq.top());
    rsum +=(lpq.top());
    rpq.push((lpq.top()));
    lpq.pop();
    balance();
}
void reset(){  
    lsum=0;rsum=0;
    while(!lpq.empty()) lpq.pop();
    while(!rpq.empty()) rpq.pop();
}
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);  
    int T=1;
    // cin>>T;
    while(T--){
        int k,n;
        cin >> k >> n;
        vpi A;
        ll side = 0;
        rep(i,0,n){
            char x,y;
            int a,b;
            cin >> x >> a >> y >> b;
            if(x==y) side += abs(b-a);
            else A.push_back({a,b});
        }
        sort(all(A),[](pi &a,pi &b){
            return a.first+a.second < b.second+b.first;
        });
        reset();
        vi pref(A.size()+1,0);
        rep(i,0,A.size()){
            insert(A[i].first);
            insert(A[i].second);
            pref[i+1] = rsum -lsum;
        }
        side +=A.size();
        ll ans = pref.back();
        if(k==2){
            reset();
            per(i,0,A.size()){
                insert(A[i].first);
                insert(A[i].second);
                ans =min(ans,rsum-lsum+pref[i]);
            }
        }
        put(side+ans);
    }

    return 0;
}
