import java.util.Arrays;
import java.util.*;
class Solution {
    Integer[] dp;
    int solve(int y,List<List<Integer>> arr){
        int n = arr.size();
        if(y==n) return 0;
        if(dp[y]!=null) return dp[y];
        int[][] adj = {
            {1,1},{0,1}  
        };
        int min = Integer.MAX_VALUE;
        for (int x = 0; x < arr.get(0).size(); x++) {
            for (int[] a : adj) {
                min = Math.min(solve(y+a[1], arr)+arr.get(y).get(x), min);
            }
        }
        return dp[y] = min;
        
    }
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        dp = new Integer[n];
        return solve(0, triangle);        
    }
}