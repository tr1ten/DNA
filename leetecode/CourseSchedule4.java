import java.beans.Visibility;
import java.util.*;;
class Solution {
    List<Integer>[] adj;
    void dfs(int u,boolean[] visited){
        visited[u] = true;
        for (int v:adj[u]) {
            if(!visited[v]) dfs(v, visited);
        }

    }
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        adj = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int[] p : prerequisites) {
            adj[p[0]].add(p[1]);
        }
        boolean[][] dp = new boolean[numCourses][numCourses];
        for (int i = 0; i < numCourses; i++) {
            dfs(i, dp[i]);            
        }
        List<Boolean> res = new ArrayList<>();
        for (int[] q:queries) {
            res.add(dp[q[0]][q[1]]);
        }
        return res;
    }
}