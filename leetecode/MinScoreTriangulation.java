// same as chain matrix multiplication
class Solution {
    public int minScoreTriangulation(int[] arr) {
        int N=arr.length;
        int[][] dp = new int[N][N];
        for(int i=2;i<N;i++){
            for(int j=0;j+i<N;j++){
                int k = j+i;
                int mn = Integer.MAX_VALUE;
                for(int x=j+1;x<k;x++){
                    mn= Math.min(mn,dp[j][x] + dp[x][k] + arr[j]*arr[k]*arr[x]);
                }
                dp[j][k] = mn;
            }
        }
        return dp[0][N-1];
    }
}