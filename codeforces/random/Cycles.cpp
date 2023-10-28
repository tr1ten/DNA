#include <bits/stdc++.h>

using namespace std;
bool isCycle = 0;
const int N = 1e5 + 5;
vector<set<int>> adj;
int av[N]; // arrival
int low[N]; // lowest id reachable from current node
bool vis[N];
int n,m;
unordered_map<int,unordered_map<int,bool>> bridge;
int timer=0;
void dfs(int u,int p){
    av[u] = low[u] = timer++;
    vis[u]  = 1;
    for(auto v:adj[u]){
        if(v==p) continue;
        if(!vis[v]) dfs(v,u);
        low[u] = min(low[v],low[u]);
        if(low[v]>av[u]){
            bridge[u][v] = 1;
            bridge[v][u] = 1;
        }
            
    }
}

void dfs2(int u,int p,set<int> &path){
    vis[u] = 1;
    path.insert(u);
    for(auto v:adj[u]){
        if(v==p) continue;
        if(vis[v]){
            if(path.find(v)!=path.end()) {
                isCycle =1;
            }
        }
        else{
            dfs2(v,u,path);
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    adj.resize(n);
    int a[m];
    for(int i=0;i<m;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        int v;
        cin >> v;
        v--;a[i]--;
        adj[a[i]].insert(v);
        adj[v].insert(a[i]);
    }
    dfs(0,-1);
    for(auto i:bridge){
        for(auto j:i.second){
            adj[i.first].erase(adj[i.first].find(j.first));
        }
    }
    vector<int> ans(n,0);
    set<int> path;
    memset(vis,0,sizeof vis);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            isCycle = 0;
            path.clear();
            dfs2(i,-1,path);
            if(isCycle){
                for(auto v:path){
                ans[v]=1;
            }
            }
        }
    }
    for(auto i:ans){
        cout << i << " ";
    }
    cout<<endl;
    
    return 0;
}
