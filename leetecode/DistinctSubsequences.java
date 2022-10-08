class Solution {
    Integer[][] dp;
    int solve(String s,int si, String t,int ti){
        int sn = s.length();
        int tn = t.length();
        if(si>=sn) return ti>=tn ? 1 : 0;
        if(ti>=tn) return  1;
        if(dp[si][ti]!=null) return dp[si][ti];
        if(s.charAt(si)!=t.charAt(ti)) return dp[si][ti]= solve(s, si+1, t, ti);
        return  dp[si][ti] = solve(s, si+1, t, ti+1) + solve(s, si+1, t, ti);
    }
    public int numDistinct(String s, String t) {
        dp = new Integer[s.length()][t.length()];
        return solve(s, 0, t, 0);
    }
}