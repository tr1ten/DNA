package DS;

import java.util.ArrayList;

public class WtDirectedGraph {
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
    public class Edge{
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
}
