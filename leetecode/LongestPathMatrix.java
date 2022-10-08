class Solution {
    Integer[][] dp;
    int dfs(int[][] matrix,int i,int j){
        if(dp[i][j]!=null) return dp[i][j];
        int n =matrix.length;
        int m = matrix[0].length;
        int max = 0;
        if(i-1>=0 && matrix[i-1][j]<matrix[i][j]) max = Math.max(max,dfs(matrix,i-1,j));
        if(j-1>=0 && matrix[i][j-1]<matrix[i][j]) max = Math.max(max,dfs(matrix,i,j-1));
        if(i+1<n && matrix[i+1][j]<matrix[i][j]) max = Math.max(max,dfs(matrix,i+1,j));
        if(j+1<m && matrix[i][j+1]<matrix[i][j]) max = Math.max(max,dfs(matrix,i,j+1));
        dp[i][j] = max+1;
        return dp[i][j];
    }
    public int longestIncreasingPath(int[][] matrix) {
        int n =matrix.length;
        int m = matrix[0].length;
        dp = new Integer[n][m];
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                max = Math.max(max, dfs(matrix, i, j));
            }
        }
        return max;
    }
}