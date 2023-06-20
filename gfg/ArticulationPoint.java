import java.util.ArrayList;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;

class Solution
{

    static Integer[] lowestTime;
    static Integer[] visitTime;
    static boolean[] ap;
    static int time;
    static void dfs(int u,int p, ArrayList<ArrayList<Integer>> adj){
        lowestTime[u] = time;
        visitTime[u] = time;
        time++;
        int child = 0;
        for (int v:adj.get(u)) {
            if(v==p) continue;
            if(lowestTime[v]==null){
                 dfs(v, u,adj);
                 lowestTime[u] = Math.min(lowestTime[u], lowestTime[v]);
                 // compare it with visit time, since we might have also visited some lower nodes but that doesn't make it non ap
                if(lowestTime[v]>=visitTime[u] && p!=-1) ap[u] = true; // only check for newly discovered node, since already visited node cannot be broken by this
                child++;
            }
            else{
                lowestTime[u] = Math.min(lowestTime[u], visitTime[v]);
            }
        }
        if(p==-1 && child>1) ap[u] = true;
    }
    public ArrayList<Integer> articulationPoints(int V,ArrayList<ArrayList<Integer>> adj)
    {
        time = 0;
        lowestTime = new Integer[V];
        visitTime = new Integer[V];
        ap = new boolean[V];
        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if(visitTime[i]==null) dfs(i, -1, adj);
        }
        for (int i = 0; i < V; i++) {
            if(ap[i]) res.add(i);
        }
        if(res.size()==0) res.add(-1);
        return res;
    }
}