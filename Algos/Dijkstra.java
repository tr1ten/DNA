package Algos;

import DS.IndexMinPQ;
import DS.WtDirectedGraph;
import DS.WtDirectedGraph.Edge;

/**
 * Dijkstra
 * Not for Negative wts
 */
public class Dijkstra {
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
            for (Edge e:G.adj(V)) {
                relax(e);
            }
        }

    }
}