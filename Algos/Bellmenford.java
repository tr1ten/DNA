package Algos;

import DS.WtDirectedGraph;
import DS.WtDirectedGraph.Edge;

// very basic implementation
public class Bellmenford {
    double[] distTo;
    int[] edgeTo;

    void relax(Edge e){
        int u=e.from(), v=e.to();
        if(distTo[v]>distTo[u]+e.wt()){
            distTo[v] = distTo[u]+e.wt();
            edgeTo[v] = u;
        }
    }

    Bellmenford(WtDirectedGraph G,int s){
        int V = G.V;
        distTo = new double[V];
        edgeTo = new int[V];
        for (int i = 0; i < edgeTo.length; i++) {
            distTo[i] = Double.MAX_VALUE;
        }
        distTo[s] = 0;
        for (int i = 0; i < V; i++) {
            for (int v = 0; v < V; v++) {
                for (Edge e : G.adj(V)) {
                    relax(e);
                }
            }    
        }

    }
}
