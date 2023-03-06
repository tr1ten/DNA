#pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
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
const LL INF = 1e10+5;

// actual solutions 
//De Bruijn Sequence
string solve(int n){
    if(n==1) return "10";
    int N = 1<<(n-1);
    int start = 0;
    VII adj(N);
    VI res;
    FOR(i,0,N){
        int mask = i<<1;
        if((mask&(1<<(n-1)))) mask ^= (1<<(n-1));
        adj[i].push_back(mask+1);
        adj[i].push_back(mask);
    }
    function<void(int)> dfs = [&](int u)
    {
        while (!adj[u].empty())
        {
            int v = *adj[u].rbegin();
            adj[u].pop_back();
            dfs(v);
            res.push_back(v&1);
        }
    };
    dfs(start);
    reverse(res.begin(),res.end());
    string ret;
    FOR(k,0,n-1) ret +='0';
    trav(x,res) {
        ret += to_string(x);
    }
    return ret;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    cout << solve(N) << endl;
    return 0;
}
