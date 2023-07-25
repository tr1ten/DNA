// simple bfs with 1 wt
vi bfs(int S){
    queue<int> q;
    vi dist(n,INF);
    dist[S ] = 0;
    q.push(S);
    rep(i,0,n){
        int u = q.front();
        q.pop();
        trav(v,adj[u]){
            if(dist[v]>dist[u] +1){
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist;
}