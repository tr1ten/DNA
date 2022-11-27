

import java.util.*;
class Solution {
    static int combineBooks(int[] books, int k) {
        int n = books.length;
        if((n-1)%(k-1)>0) return -1;
        int[] pref = new int[n];
        pref[0] = books[0];
        for(int i=1;i<n;i++) pref[i] = pref[i-1]+books[i];
        int[][] dp =new int[n][n];
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j] = 9999;
                for(int p=i;p<=j-k+1;p++){
                    int left = p-1<i ? 0:  dp[i][p-1];
                    int right = p+k>j ? 0: dp[p+k][j];
                    int mid = dp[p][Math.min(p+k,j)];
                    System.out.println("i,j,p " + i+" " + j + " " + p +" val is " + left + " right " + right + " sum " + (pref[j]-(i-1<0 ? 0 : pref[i-1])));
                    dp[i][j] = Math.min(dp[i][j],left+mid+pref[j]-(i-1<0 ? 0 : pref[i-1])+right);
                }
            }
        } 
        System.out.println(Arrays.deepToString(dp));
        return dp[0][n-1];
    }
    public static void main(String[] args) {
        System.out.println(combineBooks(new int[]{3,2,4,1}, 2));;
    }
}