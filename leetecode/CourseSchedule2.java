import java.util.ArrayList;
import java.util.HashSet;
import java.util.Stack;

class Solution {
    ArrayList<ArrayList<Integer>> adjList;
    boolean haveCycle;
    boolean[] marked;
    Stack<Integer> postSt;
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
        postSt.push(vertex);
    }
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        createAdjList(numCourses, prerequisites);
        marked = new boolean[numCourses];
        postSt = new Stack<>();
        haveCycle = false;
        for (int i = 0; i < numCourses; i++) {
            if(!marked[i]) {
                var hs = new HashSet<Integer>();
                hs.add(i);
                dfs(i,hs);
            }
        }
        if(haveCycle) return new int[0];
        var ans = new int[postSt.size()];
        int i = 0;
        for (int v : postSt) {
            ans[i++] = v;
        }
        return ans;
        
    }

}