import java.util.ArrayList;
import java.util.HashSet;

class Solution {
    ArrayList<ArrayList<Integer>> adjList;
    boolean haveCycle;
    boolean[] marked;
    private void createAdjList(int n, int[][] dependencies){
        adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        for (int[] dependency : dependencies) {
            adjList.get(dependency[0]).add(dependency[1]);
        }

    }
    private void dfs(int vertex,HashSet<Integer> path)
    {
        marked[vertex] = true;
        for (int adj : adjList.get(vertex)) {
            if(path.contains(adj)) {
                haveCycle = true;
                return;
            }
            if(!marked[adj] && !haveCycle) {
                path.add(adj);
                dfs(adj,path);
                path.remove(adj);
            }
        }
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        createAdjList(numCourses, prerequisites);
        marked = new boolean[numCourses];
        haveCycle = false;
        for (int i = 0; i < numCourses; i++) {
            if(!marked[i]) {
                var hs = new HashSet<Integer>();
                hs.add(i);
                dfs(i,hs);
            }
        }
        return !haveCycle;
    } 
    public static void main(String[] args) {
        var solver = new Solution();
        int[][] pre = {{1,0}};
        System.out.println("have cycle " + solver.canFinish(2, pre));
    }
}