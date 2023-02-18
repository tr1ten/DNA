// #pragma GCC optimize(2,3,"Ofast","unroll-loops","-funroll-loops")
#include <cstdio>
#include <bits/stdc++.h>
 
using namespace std;
 
// useful defs
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VII;
typedef pair<LL, LL> PI;
typedef vector<PI> VPI;
typedef unordered_map<LL, LL> MII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, arr) for (auto &a : (arr))
#define sz(x) (int)(x).size()
#define mk_vec(name, sz, value) VI name(sz, value)
#define mk_mat(name, n, m, value) vector<vector<int>> name(n, vector<int>(m, value))
#define contains(x) find(x) != string::npos
#define take_vec(vec, sz) FOR(i, 0, sz) cin >> vec[i]
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define all(x) x.begin(), x.end()
#define less(a, b) a < b
const LL MOD = 1e9 + 7;
const LL INF = 1e16 + 5;
 
// actual solutions
// need indepth knowledge of bellmenford theory for this
// n-1 iterations for relaxations to propagate
// nth iteration to detect cycle
// n-1 more iterations more to propagate effect of negative cycle over all vertices
void solve(int n, vector<pair<PI, LL>> &edges)
{
    VI distTo(n, INF);
    distTo[0] = 0;
    VI relaxants(n,-1);
    int x;
    // n-1 is max len of path
    FOR(k, 0, n)
    {
        x = -1;
        trav(ed, edges)
        {
            int u = ed.first.first, v = ed.first.second;
            LL w = ed.second;
            if(distTo[u]==INF) continue;
            if(distTo[v]>distTo[u]+w){
                distTo[v] = distTo[u]+w;
                relaxants[v] = u; // store veertex which relaxed this vertex
                x = u; // last vertex that is relaxed
            }
        }
    }
    if(x==-1) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        FOR(i,0,n) x = relaxants[x]; // n traceback to get to cycle node
        VI cycle;
        for(int v=x;;v=relaxants[v]){
            cycle.push_back(v);
            if(v==x && cycle.size()>1) break;
        }
        reverse(cycle.begin(),cycle.end());
        trav(a,cycle) cout << a << " ";
        cout << endl;
    }
    
}
 
// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    N +=1;
    vector<pair<PI, LL>> edges;
    vector<vector<PI>> adj(N);
    FOR(i, 0, M)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.push_back({{a , b }, w});
 
    }
    FOR(i,1,N){
        edges.push_back({{0 , i}, 0});
    }
    solve(N, edges);
    
    return 0;
}