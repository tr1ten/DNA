class Solution {
    Long[][] dp;
    long solve(int[] nums,boolean isPlus, int i){
        if(i>=nums.length) return 0;
        int k = isPlus ? 1 : 0;
        if(dp[i][k]!=null) return dp[i][k]; 
        dp[i][k] = Math.max(solve(nums,!isPlus,i+1)+(isPlus ? nums[i] : -1*nums[i]),solve(nums,isPlus,i+1));
        return dp[i][k];
    }
    public long maxAlternatingSum(int[] nums) {
        dp = new Long[nums.length][2];
        return solve(nums,true,0);
    }
}