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
            adjList.get(dependency[0]-1).add(dependency[1]-1);
        }

    }
    
    public int findJudge(int n, int[][] trust) {
        createAdjList(n, trust);
        ArrayList<Integer> potJudge = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if(adjList.get(i).size()==0) potJudge.add(i);
            if(potJudge.size()>1) return -1;
        }
        if(potJudge.size()!=1) return -1;
        int count = 0;
        int judge = potJudge.remove(0)+1;
        for (int[] adj : trust) {
            if(adj[1]==judge) count++;
        }
        return count!=(n-1) ? -1 : judge;
    }
    public static void main(String[] args) {
        int[][] trust = {{1,3},{2,3}};
        var solver = new Solution();
        System.out.println("ans : " + solver.findJudge(3,trust));
    }
}