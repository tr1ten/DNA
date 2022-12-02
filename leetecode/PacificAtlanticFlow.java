import java.util.*;

class Solution {
    int n;
    int m;
    int _index(int i,int j){
        return i*m + j;
    }
    int[] _coord(int x){
        return new int[]{x%m,x/m}; // (x,y)
    }
    boolean isValid(int x,int y) {return !(x<0 || y<0 || x>=m || y>=n);}
    void dfs(int i,int j,int[][] heights ,QuickUnionWt qf){
        int[][] adj = {{-1,0},{1,0},{0,1},{0,-1}};
        for (int[] a : adj) {
            int y = i+a[1],x=j+a[0];
            if(!isValid(x, y) || qf.connected(m*n, _index(y, x)) || heights[y][x]<heights[i][j]) continue;
            qf.union(n*m, _index(y, x));
            int temp = heights[i][j];
            heights[i][j] = -1;
            dfs(y, x, heights, qf);
            heights[i][j] = temp;
        }

    }
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        n = heights.length;
        m = heights[0].length;
        QuickUnionWt pacUf = new QuickUnionWt(n*m + 1);
        QuickUnionWt atlUf = new QuickUnionWt(n*m + 1);   
        for (int i = 0; i < n; i++) {
            pacUf.union(n*m, _index(i, 0));
            atlUf.union(n*m , _index(i, m-1));
            dfs(i, 0, heights, pacUf);
            dfs(i, m-1, heights, atlUf);
        
        }
        for (int i = 0; i < m; i++) {
            pacUf.union(n*m, _index(0, i));
            atlUf.union(n*m , _index(n-1, i));
            dfs(0, i, heights, pacUf);
            dfs(n-1, i, heights, atlUf);
        }
        
        List<List<Integer>> res= new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ind= _index(i, j);
                if(atlUf.connected(m*n, ind) && pacUf.connected(n*m, ind)){
                    List<Integer> ans = new ArrayList<>();
                    ans.add(i);
                    ans.add(j);
                    res.add(ans);
                }
            }
        }
        return res;
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