import java.util.ArrayList;

class Solution {
    class Pair{
        int vertex;
        int wt;
        Pair(int v,int w){
            vertex = v;
            wt = w;
        }
    }
    boolean[] visited;
    ArrayList<Integer>[] adjList;
    Pair[] cache;
    private Pair quitChild(int v,int[] quiet){  
        visited[v] =true;
        int min = quiet[v];
        Pair mpair = new Pair(v, min);
        Pair p;
        for (int ad : adjList[v]) {
            if(visited[ad]){
                p = cache[ad];
            }
            else p= quitChild(ad, quiet);
            if(p.wt<mpair.wt){
                mpair = p;
            }
        }
        cache[v] = mpair;
        return mpair;


    }
    public int[] loudAndRich(int[][] richer, int[] quiet) {
        adjList = new ArrayList[quiet.length];
        for (int i = 0; i < quiet.length; i++) {
            adjList[i] = new ArrayList<>();
        }
        for (int[] is : richer) {
            adjList[is[1]].add(is[0]);
        }
        cache = new Pair[quiet.length];
        int[] ans = new int[quiet.length];
        visited = new boolean[quiet.length];
        for (int i = 0; i < ans.length; i++) {
            ans[i] = quitChild(i, quiet).vertex;
        }
        return ans;
    }
}