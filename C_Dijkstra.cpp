#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e10;
vector<int> dijsktra(int S,vector<vector<pair<int,ll>>> &adj){
    int n = adj.size();
    vector<ll> dist(n,INF);
    vector<int> par(n,-1);
    dist[S] = 0;
    par[S] = S;
    priority_queue<pair<ll,int>> pq;
    pq.push(make_pair(0LL,S));
    while(!pq.empty()){
        auto u = pq.top();
        pq.pop();
        if(u.first>dist[u.second]) continue;
        for(auto &v:adj[u.second]){
            if(dist[v.first]>dist[u.second] + v.second){
                dist[v.first] = dist[v.first]>dist[u.second] + v.second;
                par[v.first] = u.second;
                pq.push(make_pair(dist[v.first],v.first));
            }
        }
    }
    return par; // or par according to needs
}

int main(int argc, char const *argv[])
{
    int n,m;
    int D = n-1;
    int S = 0;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> adj;
    while(m--){
        int u,v;
        ll w;
        cin >> u >> v >> w;
        u--;v--;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    auto par = dijsktra(S,adj);
    if(par[D]==-1) cout << (-1) << endl;
    else{
        int u=D;
        vector<int> path;
        while(par[u]!=u) {
            path.push_back(u);
            u = par[u];
        }
        while(path.size()) {cout << path.back() << " "; path.pop_back();}

    }
    return 0;
}
