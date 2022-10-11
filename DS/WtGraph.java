package DS;

import java.util.ArrayList;
import java.util.List;

public class WtGraph {
    public int V;
    ArrayList<Edge>[] adjList;
    ArrayList<Edge> edges;
    public WtGraph(int V){
        this.V = V;
        edges = new ArrayList<>();
        adjList = (ArrayList<Edge>[])new ArrayList[V];
        for (int i = 0; i < adjList.length; i++) {
            adjList[i] = new ArrayList<>();
        }
    }
    public void addEdge(int u,int v,double wt){
        Edge e = new Edge(u, v, wt);
        adjList[u].add(e);
        adjList[v].add(e);
        edges.add(e);

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
        
        public int either(){
            return u;
        }
        public int other(int x){
            if(x==u) return v;
            else return u;
        }
    }
    public List<Edge> edges(){
        return edges;
    }

}
