#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL; 
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<int,int> PI;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,arr) for (auto& a: (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name,sz,value) VI name(sz,value)
#define mk_mat(name,n,m,value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
const LL MOD = 1e9+7;
const int INF = 1e8+5;

// actual solutions 
LL solve(LL n,LL t,VI &vec){
    sort_vec(vec);
    auto ok= [&](LL mid){
        LL cnt = 0;
        trav(x,vec){
            cnt += (mid/x);
        }
        return cnt>=t; 
    };
    LL lo=1L;
    LL hi= (LL)1e18;

    while(lo<hi){
        LL mid = (lo+hi)/2L;
        if(ok(mid)) hi = mid;
        else lo = mid+1L;
    }
    return hi;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    LL N,T;
    cin>>N >> T;
    mk_vec(vec,N,0);
    take_vec(vec,N);
    cout << solve(N,T,vec) << endl;
    return 0;
}
