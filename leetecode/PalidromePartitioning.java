class Solution {
    boolean isPal(int i,int j,String s){
        while(i<j) {
            if(s.charAt(i++)!=s.charAt(j--)) return false;
        }
        return true;
    }
    public int minCut(String s) {
        int n = s.length();
        int[] dp = new int[n+1];
        dp[n] = 0;
        int j=n-1;
        for(int i=0;i<n;i++){
            int min = Integer.MAX_VALUE;
            while(j>=i){
                if(isPal(i,j,s)) {
                    min=Math.min(1+dp[j+1],min);
                }
                j--;
            }
            dp[i] = min;
        }
        return dp[0]-1;
    }
}