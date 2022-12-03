import java.util.ArrayList;
import java.util.Iterator;
import java.util.NoSuchElementException;

import DS.IndexMinPQ;
class Dijkstra {
    IndexMinPQ<Double> pq;
    double[] distTo;
    int[] edgeTo;

    void relax(Edge e){
        int u=e.from(), v=e.to();
        if(distTo[v]>distTo[u]+e.wt()){
            distTo[v] = distTo[u]+e.wt();
            edgeTo[v] = u;
            if(pq.contains(v)) pq.decreaseKey(v, distTo[v]);
            else pq.insert(v, distTo[v]);

        }
    }

    Dijkstra(WtDirectedGraph G,int s){
        int V = G.V;
        distTo = new double[V];
        edgeTo = new int[V];
        pq = new IndexMinPQ<>(V);
        for (int i = 0; i < edgeTo.length; i++) {
            distTo[i] = Double.MAX_VALUE;
        }
        distTo[s] = 0;
        pq.insert(s, 0.0);
        while (!pq.isEmpty()) {
            int v = pq.delMin();
            for (Edge e:G.adj(v)) {
                relax(e);
            }
        }

    }
}
class Edge{
    int u,v;
    double wt;
    Edge(int u,int v,double wt){
        this.u = u;
        this.v = v;
        this.wt = wt;
    }
    public double wt(){
        return wt;
    }
    public int from(){
        return u;
    }
    public int to(){
        return v;
    }
}
class WtDirectedGraph {
    public int V;
    ArrayList<Edge>[] adjList;
    WtDirectedGraph(int V){
        this.V = V;
        adjList = (ArrayList<Edge>[])new ArrayList[V];
        for (int i = 0; i < adjList.length; i++) {
            adjList[i] = new ArrayList<>();
        }
    }
    public void addEdge(int u,int v,double wt){
        adjList[u].add(new Edge(u, v, wt));

    }
    public ArrayList<Edge> adj(int u){
        return adjList[u];
    }
}

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        WtDirectedGraph g = new WtDirectedGraph(n);
        for (int[] is : times) {
            g.addEdge(is[0]-1, is[1]-1, is[2]);
        }
        Dijkstra ds = new Dijkstra(g, k-1);
        double mx = Double.MIN_VALUE;
        for (double d : ds.distTo) {
            mx = Math.max(d, mx);
        }
        return mx==Double.MAX_VALUE ? -1 : (int)mx;

    }
}