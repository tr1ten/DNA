import java.util.ArrayList;

class Solution
{
    static int[] distTo;
    static void relax(ArrayList<Integer> e){
        int u=e.get(0), v=e.get(1),wt=e.get(2);
        if(distTo[v]>distTo[u]+wt){
            distTo[v] = distTo[u]+wt;
        }
    }
    static int[] bellman_ford(int V, ArrayList<ArrayList<Integer>> adj, int S)
    {
        distTo = new int[V];
        for (int i = 0; i < V; i++) {
            distTo[i] = Integer.MAX_VALUE;
        }
        distTo[S] = 0;
        // make adjancy list
        ArrayList<Integer>[] 
        for (int i = 0; i < V; i++) {
            for (int v = 0; v < V; v++) {
                for ( e: adj.get(v)) {
                    relax(e);
                }
            }    
        }
        return distTo;
        
    }
}
