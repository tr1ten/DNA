import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;
class Solution {
    Queue<int[]> mst(List<int[]> edges,int V){
        Queue<int[]> mst = new LinkedBlockingQueue<>();
        Queue<int[]> q = new LinkedBlockingQueue<>();
        for (int[] ed:edges) {
            q.add(ed);
        }
        QuickUnionWt uf = new QuickUnionWt(V);
        while (!q.isEmpty() && mst.size()<V-1) {
            int[] edge = q.poll();
            int v=edge[1],u=edge[0];
            if(!uf.connected(v, u)){
                mst.add(edge);
                uf.union(v, u);
            }
        }
        return mst;
    }
    public int removeStones(int[][] stones) {
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < stones.length; i++) {
            for (int j = i+1; j < stones.length; j++) {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) edges.add(new int[]{i,j});
            }
        }
        return mst(edges, stones.length).size();
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