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
#define mk_mat(name,n,m,value) vector<vector<LL>> name(n, vector<LL>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec,sz) FOR(i,0,sz) cin>>vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e10+5;
int p[25];

// actual solutions 
// Number of hamiltonian paths from src to dest
LL hamiltonian(VII m,vector<vector<int>> &adj,int src,int dest){
    int n = m.size();
    mk_mat(dp,n,p[n],0); // dp[end][mask] number of hamil path ending at end node containing path of mask
    // setup
    FOR(u,0,n){
        if(u==src) continue;
        dp[u][(p[src]) | (p[u])] = m[src][u];
    }
    FOR(state,1,p[n]){
        if((state&(p[src]))==0) continue; // must contain source in the path
        FOR(nxt,0,n){
            if(nxt==src || (state&(p[nxt]))==0) continue;
            int wstate = state ^ (p[nxt]);
            trav(e,adj[nxt]){
                if(e==src || e==nxt || (wstate&p[e]==0)) continue;
                dp[nxt][state] = (dp[nxt][state] +  dp[e][wstate])%MOD;
            }

        }
    }    
    return dp[dest][p[n] - 1];
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    VII m(N,vector<LL>(N));
    int src = 0;
    int dst = N-1;
        FOR(i,0,25) {
        p[i] = 1<<i;
    }   
    vector<vector<int>> adj(N);
    FOR(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        m[a-1][b-1]++;
        adj[b-1].push_back(a-1);
    }   
    cout << hamiltonian(m,adj,src,dst) << endl;
    return 0;
}
