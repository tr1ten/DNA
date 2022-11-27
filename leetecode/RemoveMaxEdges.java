class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        QuickUnionWt auf = new QuickUnionWt(n);
        QuickUnionWt buf = new QuickUnionWt(n);
        int es = edges.length;
        for (int[] ed : edges) {
            if(ed[0]==3 && !auf.connected(ed[1]-1, ed[2]-1)) {
                auf.union(ed[1]-1, ed[2]-1);
                buf.union(ed[1]-1, ed[2]-1);
                es--;
            }
        }
        for (int[] ed : edges) {
            if(ed[0]==1 && !auf.connected(ed[1]-1, ed[2]-1)){
                 auf.union(ed[1]-1, ed[2]-1);
                es--;
                }
                 if(ed[0]==2 && !buf.connected(ed[1]-1, ed[2]-1)){
                 buf.union(ed[1]-1, ed[2]-1);
                es--;
                }
        }
        if(auf.count()!=1 || buf.count()!=1) return -1;
        return es;
        
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