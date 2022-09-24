import java.util.ArrayList;
import java.util.ArrayList;

class Solution {
    private boolean dfs(int[] dp,int[] arr,int target,int ind){
        if(ind<0) return true;
        for(int i=0;i<4;i++){
            if(dp[i]+arr[ind]<=target){
                dp[i] += arr[ind];
                if(dfs(dp,arr,target,ind-1)) return true;
                dp[i] -=arr[ind];
            }
        }
        return false;
    }
    public boolean makesquare(int[] matchsticks) {
        int n = matchsticks.length;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum+=matchsticks[i];
        }
        int side = sum/4;
        if(side*4!=sum) return false;
        Arrays.sort(matchsticks);
        return dfs(new int[4],matchsticks,side,n-1);
    }
}