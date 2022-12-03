import java.util.PriorityQueue;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.LinkedBlockingQueue;

import DS.IndexMinPQ;
import DS.LinkUnionFind;
import DS.WtGraph;
import DS.WtGraph.Edge;;
interface MST{
    Iterable<Edge> mst();
}
/**
 * PrimMST -Prims similar to kruskal 
 * Good for Dense Graph
 * TC - O(ElogV)
 */
class PrimsMST implements MST {
    boolean[] marked;
    PriorityQueue<Edge> pq;
    Queue<Edge> q;
    PrimsMST(WtGraph g){
        marked = new boolean[g.V];
        pq = new PriorityQueue<>((a,b)->Double.compare(a.wt(), b.wt()));
        q = new LinkedBlockingDeque<>();
        visit(g, 0);
        while (!pq.isEmpty()) {
            Edge e = pq.poll();
            int v = e.either();
            int u = e.other(v);
            if(marked[v] && marked[u]) continue; // since we don't have decrease key in pq, we have to check if other vertex is marked
            q.add(e);
            if(!marked[u]) visit(g, u);
            if(!marked[v]) visit(g, v);
        }

    }
    void visit(WtGraph g,int v){
        marked[v] =true;
        for(Edge e:g.adj(v)){
            if(!marked[e.other(v)]) pq.add(e);
        }
    }
    public Iterable<Edge> mst(){
        return q;
    }
}
/*
 * Kruskal - Sort the edges, add to mst if doesn't create cycle until V-1
 * Good for Sparse graph
 * TC - O(ElogE)
 */
class KruskalMST implements MST{
    PriorityQueue<Edge> pq;
    Queue<Edge> q;
    KruskalMST(WtGraph g){
        pq = new PriorityQueue<>((a,b)->Double.compare(a.wt(), b.wt()));
        pq.addAll(g.edges());
        q = new LinkedBlockingDeque<>();
        LinkUnionFind uf = new LinkUnionFind(g.V);
        while (q.size()<g.V-1) {
            Edge e = pq.poll();
            int v = e.either();
            int u = e.other(v);
            if(uf.find(u)!=uf.find(v)) {
                q.add(e);
                uf.union(u, v);
            }
        }
    }
    public Iterable<Edge> mst(){
        return q;
    }
}
class PrimsMSTIPQ implements MST{
    IndexMinPQ<Edge> ipq;
    Queue<Edge> mst;
    PrimsMSTIPQ(WtGraph g){
        ipq =  new IndexMinPQ<>(g.V);
        mst = new LinkedBlockingQueue<>();
        for(int i=1;i<g.V;i++){
            ipq.insert(i,g.new Edge(i, i, Double.POSITIVE_INFINITY));
        }
        visit(0, g);
        while(mst.size()<g.V-1) {
            int u = ipq.minIndex();
            Edge ed = ipq.keyOf(u);
            ipq.delMin();
            visit(u, g);
            mst.add(ed);
        }
    }
    void visit(int u,WtGraph g){
        for(Edge ed:g.adj(u)){
            int v = ed.other(u);
            if(!ipq.contains(v)) continue;
            else if(ipq.keyOf(v).wt()>ed.wt()) ipq.decreaseKey(v,ed);
        }
    }
    @Override
    public Iterable<Edge> mst() {
        return mst;
    }
}
// test mst

class TestMST {
    public static void main(String[] args) {
        WtGraph g = new WtGraph(8);
        g.addEdge(0, 1, 0.16);
        g.addEdge(0, 2, 0.26);
        g.addEdge(0, 4, 0.38);
        g.addEdge(1, 3, 0.29);
        g.addEdge(1, 5, 0.32);
        g.addEdge(2, 3, 0.17);
        g.addEdge(2, 7, 0.34);
        g.addEdge(3, 6, 0.52);
        g.addEdge(4, 5, 0.35);
        g.addEdge(4, 7, 0.37);
        g.addEdge(5, 7, 0.28);
        g.addEdge(6, 7, 0.19);
        MST mst = new PrimsMSTIPQ(g);
        double sum = 0;
        for (Edge e : mst.mst()) {
            System.out.println(e.either()+" "+e.other(e.either())+" "+e.wt());
            sum+=e.wt();
        }
        // 1.73
        System.out.printf("Total weight: %.2f",sum);
    }
}

