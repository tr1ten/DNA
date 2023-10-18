void dfs(int u,int p,vii &adj,vi &dp,vi &clr){
    int cur = clr[u]==0 ? -1 : 1;
    ll res = 0;
    trav(v,adj[u]){
        if(v==p) continue;
        dfs(v,u,adj,dp,clr);
        res += max(0ll,dp[v]);
    }
    dp[u] = cur + res;
}
void dfs2(int u,int p,vii &adj,vi &dp,vi &clr){
    trav(v,adj[u]){
        if(v==p) continue;
        dp[v] +=max(0ll,dp[u]-max(0ll,dp[v]));
        dfs2(v,u,adj,dp,clr);
    }
}