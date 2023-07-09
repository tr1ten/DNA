#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int,double>>> adj;
vector<double> clr;
int get(bool g) {return g?1.5:0;}
bool bipartite(int u,double g){
    clr[u] = g;
    trav(v,adj[u]){
        if(clr[v.first]!=INF){
            if((clr[v.first]+g)!=v.second) {return 0;}
            continue;
        }
        if(!bipartite(v.first,v.second-g)) {return 0;}
    }
    return 1;
}