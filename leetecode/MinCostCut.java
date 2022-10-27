import java.util.Arrays;
import java.util.HashMap;
import java.util.TreeSet;

class Solution {
    
    public int minCost(int n, int[] cuts) {
        int N = cuts.length;
        Arrays.sort(cuts);
        int[][] dp= new int[N][N];
        for (int i = N-1; i <N; i++) {
            for (int j = i; j <N; j++) {
                int min = Integer.MAX_VALUE;
                for (int v = i; v <=j; v++) {
                    int len =((v+1>j?n:cuts[v+1])-(v-1<i?0:cuts[v-1]));
                    int left = v-1<0 ? 0 : dp[i][v-1];
                    int right = v+1<N ? dp[v+1][j] : 0;
                    // System.out.println("len " + len + " for " + i + v + j);
                    min = Math.min(len + left+right ,min);
                }
                dp[i][j] = min;
            }
            System.out.println(Arrays.toString(dp[i]));
        }
        return dp[0][N-1];

    }
}