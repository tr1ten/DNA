
class SorroundRegion {
    public void solve(char[][] board) {
        int n = board.length;
        int m = board[0].length;
        int[][] adj = {{0,1},{0,-1},{-1,0},{1,0}};
        QuickUnionWt qu = new QuickUnionWt(m*n+1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j]=='O'){
                    if(i==0 || j==0 || i==n-1 || j==m-1) qu.union(m*n, i*m + j);
                    else{
                        for (int[] js : adj) {
                            int ys = js[1] + i, xs = js[0]+j;
                            if(ys<n && ys>=0 && xs<m && xs>=0 && board[ys][xs]=='O') {
                                qu.union(i*m +j, ys*m+xs);
                            }
                        }
                    }
                }                
            }
        }
        int root = qu.find(m*n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(board[i][j]=='O' && qu.find(i*m +j)!=root) board[i][j] = 'X';
            }
        }        

        return;
    }
    // more common way
    class Solution {
        char[][] gb;
    boolean[][] visited;
    void dfs(int i,int j){
        if(i<0 || j<0 || i>=visited.length || j>=visited[0].length) return;
        if(visited[i][j]) return ;
        visited[i][j] = true;
        if(gb[i][j]=='O'){
            gb[i][j] = '#';
            dfs(i+1, j);
            dfs(i-1, j);
            dfs(i, j+1);
            dfs(i, j-1);
        }
        
    }
    public void solve(char[][] board) {
        gb = board;
        visited = new boolean[board.length][board[0].length];
        for (int i = 0; i < board[0].length; i++) {
            if(board[0][i]=='O') dfs(0, i);
            if(board[board.length-1][i]=='O') dfs(board.length-1, i);
        }
        for (int i = 0; i < board.length; i++) {
            if(board[i][0]=='O') dfs(i, 0);
            if(board[i][board[0].length-1]=='O') dfs(i, board[0].length-1);
        }        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='#') board[i][j]='O';
            }
        }
        return;
    }
}

    public static void main(String[] args) {
        SorroundRegion s = new SorroundRegion();
        char[][] board = new char[][]{
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}
        };
        s.solve(board);
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }
}
class QuickUnionWt {
    private int[] parent;   // parent[i] = parent of i
    private int[] size;     // size[i] = number of elements in subtree rooted at i
    private int count;      // number of components

    /**
     * Initializes an empty union-find data structure with
     * {@code n} elements {@code 0} through {@code n-1}. 
     * Initially, each element is in its own set.
     *
     * @param  n the number of elements
     * @throws IllegalArgumentException if {@code n < 0}
     */
    public QuickUnionWt(int n) {
        System.out.println("new instance");
        count = n;
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    /**
     * Returns the number of sets.
     *
     * @return the number of sets (between {@code 1} and {@code n})
     */
    public int count() {
        return count;
    }
  
    /**
     * Returns the canonical element of the set containing element {@code p}.
     *
     * @param  p an element
     * @return the canonical element of the set containing {@code p}
     * @throws IllegalArgumentException unless {@code 0 <= p < n}
     */
    public int find(int p) {
        validate(p);
        while (p != parent[p])
            p = parent[p];
        return p;
    }

    // validate that p is a valid index
    private void validate(int p) {
        int n = parent.length;
        if (p < 0 || p >= n) {
            throw new IllegalArgumentException("index " + p + " is not between 0 and " + (n-1));  
        }
    }

    /**
     * Merges the set containing element {@code p} with the 
     * the set containing element {@code q}.
     *
     * @param  p one element
     * @param  q the other element
     * @throws IllegalArgumentException unless
     *         both {@code 0 <= p < n} and {@code 0 <= q < n}
     */
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