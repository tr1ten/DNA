class Solution {
    boolean predict(int[] nums,int i,int j,int w,int l,boolean p){
        if(i>j) return p? w>=l : w>l;
        if(!predict(nums,i,j-1,l,w+nums[j],!p) || !predict(nums,i+1,j,l,w+nums[i],!p)) return true;
        return false;
    }
    public boolean PredictTheWinner(int[] nums) {
        return predict(nums,0,nums.length-1,0,0,true);
    }
}

class Solution2 {
    public boolean PredictTheWinner(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                int a = i+1<n ? dp[i+1][j] : 0;
                int b = j-1>=0 ? dp[i][j-1] : 0;
                dp[i][j] = Math.max(nums[i]-a,nums[j]-b);
            }
        }
        return dp[0][n-1] >=0;
    }
}