import java.util.Arrays;

class Solution {
           public boolean canPartition(int[] nums) {
            int ts=0;
            for(int x:nums) ts+=x;
            if(ts%2!=0) return false;
            boolean[][] dp = new boolean[nums.length+1][(ts/2) + 1];
            for (int i = 0; i <dp.length; i++) dp[i][0] = true;
            for (int i = 1; i < dp.length; i++) {
                for (int j = 1; j <= ts/2; j++) {
                    // pick
                    if(j<nums[i-1]) dp[i][j] = dp[i-1][j];
                    // pick not pick
                    else dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
            }
            return dp[nums.length][ts/2];

        }
}