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
void djisktra(int src,vector<vector<PI>> &adj){
    int n = adj.size();
    VI distTo(n,INF);
    priority_queue<PI,vector<PI>,greater<PI>> pq; // by default max heap
    distTo[src] = 0;
    pq.push({0,src});
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if(distTo[p.second]<p.first) continue;
        trav(ed,adj[p.second]){
            if(distTo[ed.first]>distTo[p.second]+ed.second){
                distTo[ed.first] = distTo[p.second]+ed.second;
                pq.push({distTo[ed.first],ed.first});
            }
        }
    }
    trav(w,distTo){
        cout << w << " ";
    }
    cout << endl;
}

// driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M;
    cin>>N>>M;
    vector<vector<PI>> adj(N);
    FOR(i, 0, M)
    {
        int a, b,w;
        cin >> a >> b >> w;
        adj[a - 1].push_back({b-1,w});
    }
    djisktra(0,adj);
    return 0;
}
