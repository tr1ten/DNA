#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

// useful defs
typedef long long LL; 
typedef vector<LL> VI;
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
void solve(size_t n,VI &vec,vector<vector<int>> &queries){
    mk_vec(pref,vec.size()+1,0);
    FOR(i,1,vec.size()+1) pref[i] = pref[i-1] + vec[i-1];
    trav(x,queries){
        int l=x[0]-1,r=x[1]-1;
        cout << (pref[r+1]-pref[l]) << endl;
    }
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,Q;
    cin>>N >> Q;
    mk_vec(vec,N,0);
    take_vec(vec,N);
    mk_mat(queries,Q,2,0);
    trav(x,queries) cin >> x[0] >> x[1];
    solve(N,vec,queries);
    return 0;
}
