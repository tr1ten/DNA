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
bool dfs(int u,int clr,VI &color,VII &adj){
    if(color[u]!=0) return color[u]==clr;
    color[u] = clr;
    trav(v,adj[u]){
        if(!dfs(v,clr*-1,color,adj)) return  false;
    }
    return true;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    VII adj(N);
    FOR(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    VI colors(N,0);
    bool flag = true;
    FOR(i,0,N){
        if(colors[i]==0 && !dfs(i,1,colors,adj)) {
            flag = false;
            break;
        }
    }
    if(flag) {
        trav(x,colors) {
            if(x==-1) cout << 2 << " ";
            else  cout << 1 << " ";
        }
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}