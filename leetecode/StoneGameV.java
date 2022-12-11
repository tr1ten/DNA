class Solution {
    int[] pref;
    private int sum(int i,int j){
        return pref[j+1] - pref[i];
    }
    private int search(int[] pre, int l, int r) {
        int sum = pre[r+1] - pre[l], L = l;
        while(l < r) {
            int m = l + ((r - l) >> 1);
            if(((pre[m+1] - pre[L]) << 1) >= sum) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
    public int stoneGameV(int[] A) {
        int n = A.length;
        pref = new int[n+1];
        int[][] dp = new int[n][n];
        int[][] lf = new int[n][n];
        int[][] rt = new int[n][n];
        for (int i = 1; i <=n; i++) pref[i] = pref[i-1] + A[i-1];
        for(int l=1;l<=n;l++){
            for (int i = 0; i < n-(l-1); i++) {
                int j=i+l-1;
                int res = 0;
                int k = search(pref, i, j);
                int left = sum(i, k);
                int right = sum(k+1, j);
                if(left==right) res = Math.max(lf[i][k],rt[k+1][j]);
                else res = Math.max(i==k ? 0 : lf[i][k-1],k==j ? 0 : rt[k+1][j]);
                dp[i][j] = res;
                lf[i][j] = Math.max(lf[i][j-1], left+right+dp[i][j]);
                rt[i][j] = Math.max(rt[i+1][j], left+right+dp[i][j]);
            }
        }
        return dp[0][n-1];

    }
}