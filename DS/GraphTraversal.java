package DS;

import java.util.Arrays;
import java.util.Queue;
import java.util.Stack;
import java.util.concurrent.LinkedBlockingQueue;

enum Color{
    WHITE,
    GRAY,
    BLACK   
}
class TestGraph {
    public static void main(String[] args) {
        // graph shown in clrs
        Graph g = new Graph(8);
        g.addEdge(0, 1);
        g.addEdge(0, 4);
        g.addEdge(1, 5);
        g.addEdge(2, 3);
        g.addEdge(2, 5);
        g.addEdge(3, 7);
        g.addEdge(3, 6);
        g.addEdge(5, 6);
        g.addEdge(6, 7);
        GraphTraversal gt = new GraphTraversal(8);
        gt.bfs(g,1);
        System.out.println(Arrays.toString(gt.distTo));
        System.out.println(Arrays.toString(gt.parentTo));
        System.out.println(Arrays.toString(gt.colorOf));
        gt = new GraphTraversal(8);
        gt.dfs(g);
        
        System.out.println("-- DFS --");
        System.out.println(Arrays.toString(gt.distTo));
        System.out.println(Arrays.toString(gt.parentTo));
        System.out.println(Arrays.toString(gt.colorOf));

    }
}
public class GraphTraversal {
    Color[] colorOf;
    int[] parentTo;
    public int[] distTo;
    int V;
    GraphTraversal(int V){
        this.V = V;
        colorOf = new Color[V];
        parentTo = new int[V];
        distTo = new int[V];
        finalDistTo = new int[V];
        for (int i = 0; i < V; i++) {
            colorOf[i] = Color.WHITE;
            distTo[i] = Integer.MAX_VALUE;
        }
    }
    public void bfs(Graph g,int s){
        colorOf[s] = Color.GRAY;
        distTo[s] = 0;
        Queue<Integer> q = new LinkedBlockingQueue<>();
        q.add(s);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (Integer v:g.adj(u)) {
                if(colorOf[v]==Color.WHITE){
                    colorOf[v] = Color.GRAY;
                    distTo[v] = distTo[u] + 1;
                    parentTo[v] = u;
                    q.add(v);
                }
            }
            colorOf[u] = Color.BLACK;
        }
    }
    int time = 0;
    int[] finalDistTo;
    private void _viist(Graph g,int u){
        time +=1;
        distTo[u] = time;
        colorOf[u] = Color.GRAY;
        for (int v:g.adj(u)) {
            if(colorOf[v]==Color.WHITE) {
                parentTo[v] = u;
                _viist(g, v);
            }
        }
        colorOf[u] = Color.BLACK;
        finalDistTo[u] = ++time;
    }
    public void dfs(Graph g){
        time = 0;
        for(int i=0;i<V;i++){
            if(colorOf[i]==Color.WHITE) _viist(g, i);
        }
    }

    private void dfs_stack(Graph g){
        time = 0;
        Stack<Integer> st = new Stack<>();
        for(int i=0;i<V;i++){
            st.push(i);
        }
        while (!st.isEmpty()) {
            int u = st.pop();
            if(colorOf[u]!=Color.WHITE) continue;
            colorOf[u] = Color.GRAY;
            distTo[u] = ++time;
            for (int v:g.adj(u)) {
                if(colorOf[v]==Color.WHITE) {
                    parentTo[v] = u;
                    st.push(v);
                }
            }
            colorOf[u] = Color.BLACK;
            finalDistTo[u] = ++time;
        }
    }

}
