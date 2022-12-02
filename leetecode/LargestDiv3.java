class Solution {
    public int maxSumDivThree(int[] nums) {
        int N = 3;
        int[] dp = new int[N]; // MOD: 0 1 2 in this case
        for(int x:nums){
            int[] temp = dp.clone(); // need to update the satates independently
            for(int state=0;state<N;state++){
                int next = (dp[state]+x)%N; // transition fn
                temp[next] = Math.max(temp[next],dp[state]+x); // updating state to optimal value 
            }
            dp = temp;
        }
        return dp[0]; // since we need divisible by N thus mod 0
    }
}