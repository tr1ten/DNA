package DS;


import java.util.ArrayList;

public class Graph{
    int V;
    ArrayList<Integer>[] adjList;
    public Graph(int V){
        this.V = V;
        adjList = (ArrayList<Integer>[])new ArrayList[V];
        for (int i = 0; i < adjList.length; i++) {
            adjList[i] = new ArrayList<>();
        }
    }
    public void addEdge(int u,int v){
        adjList[u].add(v);
        adjList[v].add(u);

    }
    public ArrayList<Integer> adj(int u){
        return adjList[u];
    }
    public int V(){ return V;}

}