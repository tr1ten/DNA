package Algos;
import DS.Graph;
import DS.QuickUnionWt;

public class ConnectedComponent {
    boolean[] visited;
    QuickUnionWt uf;
    void dfs(Graph g,int u){
        visited[u] = true;
        for (int v: g.adj(u)) {
            if(!visited[v]) {
                uf.union(v, u);
                dfs(g, v);
            }
        }
    }
    int connectedComponents(Graph g){
        int V = g.V();
        uf = new QuickUnionWt(V);
        visited = new boolean[V];
        for (int i = 0; i < V; i++) {
            dfs(g, i);
        }
        return uf.count();
    }

    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(1, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 4);
        ConnectedComponent cc = new ConnectedComponent();
        System.out.println(cc.connectedComponents(g));
    }
}
