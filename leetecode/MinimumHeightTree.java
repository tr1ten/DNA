import java.util.ArrayList;
import java.util.List;

class Solution {
    ArrayList<ArrayList<Integer>> adjList;
    private void createAdjList(int n, int[][] dependencies){
            adjList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                adjList.add(new ArrayList<>());
            }
            for (int[] dependency : dependencies) {
                adjList.get(dependency[0]).add(dependency[1]);
                adjList.get(dependency[1]).add(dependency[0]);
            }
    
        }
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        ArrayList<Integer> centroids = new ArrayList<>();
        if(n<3){
            for (int i = 0; i < n; i++) {
                centroids.add(i);
            }
            return centroids;
        }
        adjList = new ArrayList<>();
        createAdjList(n, edges);
        for (int i = 0; i < n; i++) {
            if(adjList.get(i).size()<2) {
                centroids.add(i); 
            }
        }
        var nleaves = centroids.size();
        while(nleaves>2){
            nleaves = centroids.size();
            ArrayList<Integer> newArr = new ArrayList<>();
            for (int leaf:centroids) {
                var adj = adjList.get(leaf).iterator().next();
                adjList.get(adj).remove(leaf);
                if(adjList.get(adj).size()<2) {
                    newArr.add(adj);
                }
            }
            centroids = newArr;
        }
        return centroids;
    }

}