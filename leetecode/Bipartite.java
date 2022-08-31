import java.util.HashMap;
import java.util.HashSet;

class Solution {
    boolean bipartite;
    HashMap<Integer,Integer> hs;
    private void dfs(int[][] graph, int vertex,int depth,int type){
        if(hs.containsKey(vertex)){
            if(depth%2==0 && hs.get(vertex)!=0) bipartite = false;
            return;
        }
        hs.put(vertex, type);
        for (int v : graph[vertex]) {
            dfs(graph, v, depth+1, type==0? 1 :0);
        }
    }
    public boolean isBipartite(int[][] graph) {
        bipartite = true;
        hs= new HashMap<>();
        int max = graph.length;
        for (int i = 0; i < max; i++) {
            if(!bipartite) break;
            if(!hs.containsKey(i)) dfs(graph, i, 0, 0);
        }
        return bipartite;
    }
}