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
typedef pair<LL,PI> PII;
// actual solutions 
LL prims(int n,vector<vector<PI>> &adj){
    LL res = 0;
    priority_queue<PII,vector<PII>,greater<PII>> pq;
    vector<bool> visited(n,false);
    auto visit = [&](LL u){
        visited[u] = true;
        trav(ed,adj[u]) {
            if(!visited[ed.first]) pq.push({ed.second,{ed.first,u}});
        }
    };
    visit(0);
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int u=p.second.first,v= p.second.second,w = p.first;
        if(visited[u] && visited[v]) continue;
        res += w;
        if(!visited[u]) visit(u);
        if(!visited[v]) visit(v);

    }
    return find(std::begin(visited),std::end(visited),false)!=std::end(visited) ? -1 : res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<PI>> adj(N);
    FOR(i, 0, M)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a - 1].push_back({b - 1, w});
        adj[b - 1].push_back({a - 1, w});

    }
    LL res = prims(N,adj);
    if(res<0) cout << "IMPOSSIBLE" << endl;
    else cout << res<< endl;
    return 0;   
}
