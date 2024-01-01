
vi starting;
vi ending;
int timer=0;
vii adj;
vi A;
// 2 values for start and end, for path queries 

void dfs(int u,int p){
    starting[u] = timer++;
    trav(v,adj[u] ) {
        if(v==p) continue;
        dfs(v,u);
    }
    ending[u] = timer;

}