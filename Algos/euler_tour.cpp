
vi starting;
vi ending;
int timer=0;
vii adj;
vi A;

void dfs(int u,int p){
    starting[u] = timer++;
    trav(v,adj[u] ) {
        if(v==p) continue;
        dfs(v,u);
    }
    ending[u] = timer;

}