import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class NWayDestination {
    int[] ways;
    static int MOD=1_000_000_007;
    void djisktra(List<int[]>[] graph,int s){
        ways[s] = 1;
        long[] distTo = new long[graph.length];
        Arrays.fill(distTo, Long.MAX_VALUE);
        distTo[s] = 0L;
        PriorityQueue<long[]> pq = new PriorityQueue<>((a,b)->Long.compare(a[1], b[1]));
        pq.offer(new long[]{s,0});
        while (!pq.isEmpty()) {
            long[] item = pq.poll();
            int u = (int)item[0];
            long d = item[1];
            // if outdated value 
            if(distTo[u]<d) continue;
            for (int[] ed:graph[u]) {
                int v = ed[0],dis = ed[1];
                if(distTo[v]>dis+distTo[u]) {
                    distTo[v] = (dis+distTo[u]);
                    ways[v] = ways[u];
                    pq.offer(new long[]{v,distTo[v]});
                }
                else if(distTo[v]==(dis+distTo[u])) ways[v] = (ways[v] + ways[u])%MOD;
            }
        }
        
    }
    public int countPaths(int n, int[][] roads) {
        List<int[]>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        ways = new int[n];
        for (int[] r:roads) {
            g[r[0]].add(new int[]{r[1], r[2]});
            g[r[1]].add(new int[]{r[0], r[2]});
        }
        djisktra(g, 0);
        return ways[n-1];
    }   
    public static void main(String[] args) {
        NWayDestination s = new NWayDestination();
        int n = 7;
        int[][] roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
        System.out.println(s.countPaths(n, roads));
    }
}