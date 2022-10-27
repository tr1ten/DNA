import java.util.Arrays;
// lmao so bad code O(n3)
class Solution {
    int[][] dp;
    int _get(int i,int j){
        int n = dp.length;
        if(i<0 || i>=n || j<0 || j>=n) return 0;
        return dp[i][j];
    }
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int N = arr.length;
        dp = new int[N][N];
        for(int i=N-1;i>=0;i--){
            int max = arr[i];
            for(int j=i;j<N;j++){
                max = Math.max(max, arr[j]);
                if(j-i<k){
                       dp[i][j] = (j-i+1)*max;
                }
                else{
                    max = Integer.MIN_VALUE;
                    for (int v = i; v < j; v++) {
                        max = Math.max(dp[i][v] + dp[v+1][j] , max);
                    }                    
                    dp[i][j] = max;
                }
            }
        }
        return dp[0][N-1];
    }
}

