import java.util.Arrays;

class Solution {
    public int mergeStones(int[] A, int k) {
        int n = A.length;
            int[][] dp = new int[n][n];
            int[] ps = new int[n+1];
            for(int i=0;i<n;i++) ps[i+1] += ps[i] + A[i];
            for(int i=n-2;i>=0;i--){
                for(int j=i+k-1;j<n;j++){
                    if(j-i+1<k) continue;
                    dp[i][j] = Integer.MAX_VALUE;
                    for(int v=i;v<j;v++){
                        dp[i][j] = Math.min(ps[j+1]-ps[i]+dp[i][v] + dp[v+1][j],dp[i][j]);
                    }
                }
                System.out.println(Arrays.toString(dp[i]));
            }
            return dp[0][n-1];
    }
}