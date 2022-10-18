import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

class Solution {
    List<List<double[]>> adjList;
    double dfs(int src,int target,boolean[] visited,double p){
        if(src==target) return p;
        visited[src] = true;
        double res = -1;
        for (double[] ed: adjList.get(src)) {
            int v = (int)ed[0];
            if(!visited[v]) res = dfs(v, target, visited, p*ed[1]);
            if(res>=0) return res;
        }
        return -1;
    }
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        int n = equations.size();
        int qn = queries.size();
        HashMap<String,Integer> map =new HashMap<>();
        int id=0;
        adjList = new ArrayList<>();
        for (int i=0;i<n;i++) {
            List<String> eq = equations.get(i);
            for (String v:eq) {
                if(!map.containsKey(v)) {
                    map.put(v, id++);
                    adjList.add(new ArrayList<>());
                }
            }
            int u=map.get(eq.get(0)),v= map.get(eq.get(1));
            adjList.get(u).add(new double[]{v,values[i]});
            adjList.get(v).add(new double[]{u,1.0/values[i]});            

        }
        double[] res = new double[qn];
        int k=0;
        for (List<String> q:queries) {
            Integer u = map.get(q.get(0)),v = map.get(q.get(1));
            if(u==null || v==null) res[k++] = -1;
            else{
                boolean[] visited = new boolean[id];
                res[k++] = dfs(u, v, visited, 1);
            }
        }
        return res;
        
    }
}