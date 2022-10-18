import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;

class Solution {
    List<List<Integer>> res;
    void dfs(int u,int[][] graph,LinkedHashSet<Integer> visited){
        int V = graph.length;
        visited.add(u);
        if(u==V-1){
            res.add(new ArrayList<>(visited));
        }
        for(int v:graph[u]) {
            if(!visited.contains(v)) dfs(v,graph,visited);
        }
        visited.remove(u);
    }
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        res = new ArrayList<List<Integer>>();
        dfs(0,graph,new LinkedHashSet<>());
        return res;
    }
}