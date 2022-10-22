import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

class Solution
{
    static Integer[] lowestTime;
    static Integer[] visitTime;
    static boolean[][] bridges;
    static int time;
    static int dfs(int u,int p, ArrayList<ArrayList<Integer>> adj){
        if(visitTime[u]!=null) return visitTime[u];
        lowestTime[u] = time;
        visitTime[u] = time;
        time++;
        for (int v:adj.get(u)) {
            if(v==p) continue;
            int adjMin = dfs(v, u,adj);
            if(adjMin>visitTime[u]){
                bridges[u][v] = true;
                bridges[v][u] = true;
            }
            lowestTime[u] = Math.min(lowestTime[u], adjMin);
        }
        return lowestTime[u];
    }
    //Function to find if the given edge is a bridge in graph.
    static int isBridge(int V, ArrayList<ArrayList<Integer>> adj,int c,int d)
    {
        time = 0;
        lowestTime = new Integer[V];
        visitTime = new Integer[V];
        bridges = new boolean[V][V];
        for(int i=0;i<V;i++) {
            if(visitTime[i]==null){
                dfs(i,-1,adj);
                if(bridges[c][d]) return 1;
            }
        }
        return 0;
    }
}