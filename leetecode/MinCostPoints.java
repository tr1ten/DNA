import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.Queue;

class MinCost {
    private class Edge implements Comparable<Edge>{
        private int vertex;
        private int other;
        private int wt;
        Edge(int vertex,int other){
            this.vertex = vertex;
            this.other = other;
            // calculate manhattan distance using points array
            this.wt = Math.abs(points[vertex][0]-points[other][0])+Math.abs(points[vertex][1]-points[other][1]);
        }
        public int compareTo(Edge other){
            return this.wt-other.wt;
        }
    }
    private int[][] points;
    private ArrayList<Edge>[] adjList;
    private PriorityQueue<Edge> pq;
    private boolean[] visited;
    private void visit(int vertex){
        visited[vertex] = true;
        for (Edge adj : adjList[vertex]) {
            if(!visited[adj.other]){
                pq.add(adj);
            }
        }
    }
    private int generateMSt(){
        visited = new boolean[points.length];
        pq = new PriorityQueue<>();
        Queue<Edge> mst = new ArrayDeque<>();
        visit(0);
        while(!pq.isEmpty() && mst.size()!=points.length-1){
            Edge ed = pq.remove();
            int v = ed.vertex, w = ed.other;
            if(visited[v] && visited[w]) continue;
            mst.add(ed);
            if(!visited[v]) this.visit(v);
            if(!visited[w]) this.visit(w);
        }
        int totalCost = 0;
        for (Edge edge : mst) {
            totalCost +=edge.wt;
        }
        return totalCost;
        
    }
    public int minCostConnectPoints(int[][] points) {
        this.points = points.clone();
        int V = points.length;
        if(V<=1) return 0;
        adjList = new ArrayList[V];
        for (int j = 0; j < V; j++) {
            adjList[j] = new ArrayList<>();
            for (int j2 = 0; j2 < V; j2++) {
                adjList[j].add(new Edge(j, j2));
            }
        }
        return generateMSt();
    }
    public static void main(String[] args) {
        var mincost = new MinCost();
        int[][] points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
        System.out.println("min cost " + mincost.minCostConnectPoints(points));
    }
}