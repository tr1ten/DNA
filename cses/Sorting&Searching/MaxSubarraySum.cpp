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
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e18+5;

// actual solutions 
LL solve(int n,int a,int b,VI &vec){
    LL res = -INF;
    // maximize pref[j]-pref[i] where i in range [j-b,j]
    VI pref(n+1,0);
    FOR(i,1,n+1) pref[i] = pref[i-1] + vec[i-1];
    multiset<LL> ms;
    FOR(j,a,n+1){
        if(j>b) ms.erase(ms.find(pref[j-b-1]));
        ms.insert(pref[j-a]);
        res = max(res,pref[j]-*ms.begin());
    }
    return res;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,A,B;
    cin>>N>>A>>B;
    mk_vec(vec,N,0);
    take_vec(vec,N);
    cout << solve(N,A,B,vec) << endl;
    return 0;
}
