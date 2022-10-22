import java.util.*;
class Solution {
    int[] distTo;
    void djisktra(List<int[]>[] graph,int s){
        distTo = new int[graph.length];
        Arrays.fill(distTo, Integer.MAX_VALUE);
        distTo[s] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->Integer.compare(b[1], a[1]));
        pq.offer(new int[]{s,0});
        while (!pq.isEmpty()) {
            int[] item = pq.poll();
            int u = item[0];
            int d = item[1];
            // if outdated value 
            if(distTo[u]<d) continue;
            for (int[] ed:graph[u]) {
                int v = (int) ed[0];
                int dis = ed[1];
                if(distTo[v]>dis + distTo[u]) {
                    distTo[v] = (dis+distTo[u]);
                    pq.offer(new int[]{v,distTo[v]});
                }
            }
        }
    }
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        List<int[]>[] graph = new List[n];
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < edges.length; i++) {
            graph[edges[i][0]].add(new int[]{edges[i][1],edges[i][2]});  
            graph[edges[i][1]].add(new int[]{edges[i][0],edges[i][2]});
        }
        int minT = Integer.MAX_VALUE;
        int minCity = 0;
        for (int i = 0; i < n; i++) {
            int cnt=0;
            djisktra(graph, i);
            for (int j = 0; j < n; j++) {
                if(i==j) continue;
                if(Math.abs(distTo[i]-distTo[j])<=distanceThreshold) cnt++;
            }
            if(cnt<=minT) {
                minT = cnt;
                minCity = i;
            }
        }
        return minCity;
    }
}