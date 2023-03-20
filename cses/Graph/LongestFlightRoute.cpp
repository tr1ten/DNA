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
#define print_vec(vec) trav(x,vec) cout<<x<<" "; cout<<endl;
#define all(x) x.begin(), x.end()
#define less(a,b) a<b
const LL MOD = 1e9+7;
const LL INF = 1e15+5;

// driver code
int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);
    int N,M;
    cin>>N>>M;
    VII adj(N);
    VI indeg(N,0);
    FOR(i, 0, M)
    {
        int a, b;
        cin >> a >> b;
        indeg[b-1]++;
        adj[a - 1].push_back(b-1);
    }
    // Khan algo
    queue<int> q;
    int src = 0;
    q.push(src);
    FOR(i,0,N) {
        if(indeg[i]==0) q.push(i);
    }
    VI dist(N,-1e9);
    dist[src] = 0;
    VI par(N,0);
    while (!q.empty())
    {
        int u = q.front();q.pop();
        trav(v,adj[u]){
            indeg[v]--;
            if(dist[v]<dist[u]+1){
                dist[v] = dist[u] + 1;
                par[v] = u;
            }
            if(indeg[v]==0) q.push(v);
        }
    }
    if(dist[N-1]<1) cout << "IMPOSSIBLE" << endl;
    else{
        VI ans;
        ans.push_back(N);
        while (ans.back()!=1) {
            ans.push_back(par[ans.back()-1]+1);
        }
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        print_vec(ans);
    }
    
    return 0;
}
