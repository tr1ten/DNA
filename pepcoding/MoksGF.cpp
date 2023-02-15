// #pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

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
#define FOR(i,a,b) for (LL i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (LL i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (LL)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<LL>> name(n, vector<LL>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e10+5;

// actual solutions 
void update(LL *diff,LL x,LL l,LL r,LL N){
    diff[l] +=x;
    if(r+1<N) diff[r+1] -=x;
}
// driver code
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL N,Q,M;
    cin>>N>>Q>>M;
    N++;
    LL diff[N] = {0};
    LL queries[Q][2];
    FOR(i,0,Q){
        LL l,r;
        cin >> l>>r;
        update(diff,1,l,r,N);
        queries[i][0] = l;
        queries[i][1] = r;
    }
    LL pref_eq[N+1] = {0};
    LL pref_just_larger[N+1] = {0};
    LL arr[N];
    arr[0] = diff[0];
    FOR(i,1,N) {
        arr[i] = diff[i] + arr[i-1];
    }
    FOR(i,1,N+1){ 
        pref_eq[i] = pref_eq[i-1] + (arr[i-1]==M ? 1 : 0);
        pref_just_larger[i] = pref_just_larger[i-1] + (arr[i-1]==M+1 ? 1 : 0);
    }
    LL total_cnt = pref_eq[N];
    LL res = 0;
    FOR(i,0,Q){
        LL l=queries[i][0],r=queries[i][1];
        res = max(res,total_cnt-(pref_eq[r+1]-pref_eq[l])+(pref_just_larger[r+1]-pref_just_larger[l]));
    }
    cout << res;
    return 0;
}
