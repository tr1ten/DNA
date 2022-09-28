import java.util.Arrays;

class MinPathSum {
    public int minPathSum(int[][] grid) {
        int n=grid.length,m=grid[0].length;
        int[][] dp = new int[n+1][m+1];
        Arrays.fill(dp[n], Integer.MAX_VALUE);
        for (int i = 0; i < dp.length; i++) dp[i][m] = Integer.MAX_VALUE;
        dp[n-1][m-1] = grid[n-1][m-1];
        dp[n][m-1] = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                dp[i][j] = grid[i][j] + Math.min(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    public static void main(String[] args) {
        MinPathSum s = new MinPathSum();
        int[][] grid = {{1,3,1},{1,5,1},{4,2,1}};
        System.out.println(s.minPathSum(grid));
    }
}