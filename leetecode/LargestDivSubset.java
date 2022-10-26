import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Stack;

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n =nums.length;
        List<Integer> res = new ArrayList<>();
        int[] dp = new int[n];
        int[] hash = new int[n];
        for(int i=0;i<n;i++) {
            dp[i] = 1;
            hash[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j=i+1;j<n;j++) {
                if((nums[j]%nums[i]==0) && (dp[i]+1)>dp[j]){
                    dp[j] = dp[i]+1;
                    hash[j] = hash[i];
                }
            }
        }
        int maxId = 0;
        int mx = 1;
        for (int i = 0; i < n; i++) {
            if(mx<dp[i]){
                maxId = hash[i];
                mx = dp[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if(hash[i]==maxId) {
                res.add(nums[i]);
            }
        }
        return res;
    }
}