class Solution {
    int MOD=1_000_000_007;
    public int rearrangeSticks(int n, int k) {
        int[][] dp = new int[k+1][n+1];
        dp[0][0] = 1;
        for(int i=1;i<=k;i++){
            for(int j=i;j<=n;j++){
                dp[i][j] = (int)(((long)(j-1)*dp[i][j-1])%MOD + (long)dp[i-1][j-1])%MOD; 
            }
        }
        return dp[k][n];
    }
}