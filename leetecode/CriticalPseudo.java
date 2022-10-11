import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

class CriticalPseudo {
    int mst(int V,int[][] edges, Integer include,Integer exclude){
        int cost=0;
        int pqi=0;
        QuickUnionWt uf = new QuickUnionWt(V);
        int sz=0;
        if(include!=null){
            int[] ed = edges[include];
            uf.union(ed[0], ed[1]);
            cost +=ed[2];
            sz++;
        }
        while (sz<V-1) {
            if(exclude!=null && pqi==exclude) pqi++;
            if(include!=null && pqi==include) pqi++;
            int[] e = pqi>=edges.length ? null : edges[pqi++];
            // if it disconnects the graph
            if(e==null) return Integer.MAX_VALUE;
            int v = e[0];
            int u = e[1];
            if(uf.find(u)!=uf.find(v)) {
                sz++;
                cost +=e[2];
                uf.union(u, v);
            }
        }
        return cost;
    }
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        List<Integer> p = new ArrayList<>();
        List<Integer> c = new ArrayList<>();
        Integer[] idx = new Integer[edges.length];
        for (int i = 0; i < idx.length; i++) {
            idx[i]=i;
        }
        Arrays.sort(idx,(a,b)->edges[a][2]-edges[b][2]);
        Arrays.sort(edges,(a,b)->Integer.compare(a[2], b[2]));
        int minC = mst(n, edges, null, null);
        for (int i = 0; i < edges.length; i++) {
            int mc = mst(n, edges, null, i);
            if(mc>minC) p.add(idx[i]);
            else {
                int mc2 = mst(n, edges, i, null);
                if(mc2==minC) c.add(idx[i]);
            }
        }
        List<List<Integer>> res = new ArrayList<>();
        res.add(p);
        res.add(c);
        return res;
    }
    public static void main(String[] args) {
        CriticalPseudo s = new CriticalPseudo();
        // 6
        // [[0,1,1],[1,2,1],[0,2,1],[2,3,4],[3,4,2],[3,5,2],[4,5,2]]
        int[][] edges = {{0,1,1},{1,2,1},{0,2,1},{2,3,4},{3,4,2},{3,5,2},{4,5,2}};
        System.out.println(s.findCriticalAndPseudoCriticalEdges(6, edges));
    }
}
class QuickUnionWt {
    private int[] parent;   // parent[i] = parent of i
    private int[] size;     // size[i] = number of elements in subtree rooted at i
    private int count;      // number of components

    public QuickUnionWt(int n) {
        count = n;
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    public int count() {
        return count;
    }

    public int find(int p) {
        validate(p);
        while (p != parent[p])
            p = parent[p];
        return p;
    }
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    // validate that p is a valid index
    private void validate(int p) {
        int n = parent.length;
        if (p < 0 || p >= n) {
            throw new IllegalArgumentException("index " + p + " is not between 0 and " + (n-1));  
        }
    }

    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        // make smaller root point to larger one
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }

}