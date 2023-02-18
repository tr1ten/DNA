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
const LL INF = 1e15+5;

// actual solutions 
LL solve(int n,VI &vec){
    return n;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M,Q;
    cin>>N >> M >> Q;
    VII distTo(N,vector<LL>(N,INF));
    FOR(i,0,N){
        FOR(j,0,N){
            if(i==j) distTo[i][j] = 0;
        }
    }
    FOR(i,0,M){
        LL u,v,w;
        cin >> u >> v >> w;
        distTo[u-1][v-1] = min(w,distTo[u-1][v-1]);
        distTo[v-1][u-1] = min(distTo[v-1][u-1],w);
    }
    // Floyd Warshall
    FOR(k,0,N){
        FOR(i,0,N){
            FOR(j,0,N){
                if(distTo[i][k]==INF || distTo[k][j]==INF) continue;
                distTo[i][j] = min(distTo[i][j],distTo[i][k]+distTo[k][j]);
            }
        }
    }
    FOR(i,0,Q){
        int u,v;
        cin >> u >> v;
        if(distTo[u-1][v-1]==INF) cout << -1 << endl;
        else cout << distTo[u-1][v-1] << endl;
    }
    return 0;
}
