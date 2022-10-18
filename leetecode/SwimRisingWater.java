public class SwimRisingWater {
    Integer[][] dp; 
    boolean[][] visited;
    int solve(int i,int j,int[][] grid,int t){
        int n = grid.length;
        int m = grid[0].length;
        if(i>=n || i<0 || j>=m || j<0) return Integer.MAX_VALUE;
        if(i==n-1 && j==m-1) return t;
        if(dp[i][j]!=null && dp[i][j]<=t) return Integer.MAX_VALUE;
        dp[i][j] = t;
        int minT = Integer.MAX_VALUE;
        int[][] pos = {{0,1},{1,0},{-1,0},{0,-1}};
        for (int[] ks : pos) {
            int id = i +  ks[1];
            int jd = j + ks[0];
            if(id>=n || id<0 || jd>=m || jd<0 || visited[id][jd]) continue;
            visited[id][jd] = true;
            minT = Math.min(solve(id, jd, grid, Math.max(t, grid[id][jd])), minT);
            visited[id][jd] = false;
        }
        return minT;
    }
    public int swimInWater(int[][] grid) {
        visited = new boolean[grid.length][grid[0].length];
        dp = new Integer[grid.length][grid[0].length];
        visited[0][0] = true;
        return solve(0, 0, grid, 0);
    }
}
