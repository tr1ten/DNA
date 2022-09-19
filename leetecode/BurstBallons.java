class Solution {
    public int maxCoins(int[] nums) {
        int N=nums.length+2;
        int[] arr = new int[N];
        for(int i=0;i<N-2;i++){
            arr[i+1] = nums[i];
        }
        arr[0] = 1;
        arr[N-1] = 1;
        int[][] dp = new int[N][N];
        for(int i=2;i<N;i++){
            for(int j=0;j+i<N;j++){
                int k = j+i;
                int mn = Integer.MIN_VALUE;
                for(int x=j+1;x<k;x++){
                    mn= Math.max(mn,dp[j][x] + dp[x][k] + arr[j]*arr[k]*arr[x]);
                }
                dp[j][k] = mn;
            }
        }
        return dp[0][N-1];
    }
}