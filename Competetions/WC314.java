import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Stack;

public class WC314 {
    public int hardestWorker(int n, int[][] logs) {
        int mx = logs[0][1];
        int eid = logs[0][0];
        for (int i = 1; i < logs.length; i++) {
            if(logs[i][1]-logs[i-1][1]>=mx){
                int diff = logs[i][1]-logs[i-1][1];
                eid =  diff==mx ? Math.min(eid, logs[i][0]) : logs[i][0];
                mx = diff;
            }            
        }
        return eid;
    }
    // String concat doesn't work
    int fm(int[] freq){
        for(int i=0;i<26;i++){
            if(freq[i]!=0) return i;
        }
        return 25;
    }
    public String robotWithString(String s) {
        Stack<Character> st = new Stack<>();
        int[] freq = new int[26];
        for (int i=0;i<s.length();i++) {
            freq[s.charAt(i)-'a']++;
        }
        StringBuilder t= new StringBuilder();
        for (char x:s.toCharArray()) {
            st.push(x);
            freq[x-'a']--;
            while (!st.empty() && (st.peek()-'a')<=fm(freq)) {
                t.append(st.pop());
            }
        } 
        return t.toString();
    }
    int[][] g;
    Integer[][][] dp;
    static int MOD = 1000000007;
    int solve(int i,int j,int k,int sum){
        if(i>=g.length || j>=g[0].length) return 0;
        sum = (sum + g[i][j])%k;
        int key = (sum)%k;
        if((i==g.length-1 && j==g[0].length-1)) return key==0 ? 1 : 0;
        if(dp[i][j][key]!=null) return dp[i][j][key];
        dp[i][j][key] = ((solve(i+1, j, k, sum)%MOD) + (solve(i, j+1, k,sum)%MOD))%MOD; 
        return dp[i][j][key];
    }
    public int numberOfPaths(int[][] grid, int k) {
        g = grid;
        dp = new Integer[g.length][g[0].length][k];
        return solve(0,0,k,0);
    }
    
}
