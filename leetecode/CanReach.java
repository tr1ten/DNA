import java.lang.annotation.Native;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;

// TLE O(nj)
// class Solution {
//     public boolean canReach(String s, int minJump, int maxJump) {
//         int n = s.length();
//         boolean[] dp = new boolean[n];
//         dp[n-1] = s.charAt(n-1)!='1';
//         if(!dp[n-1]) return false;
//         for(int i=n-2;i>=0;i--){
//             int j=i+minJump;
//             if(s.charAt(i)=='1') continue;
//             while(j <= Math.min(i + maxJump, n - 1)){
//                 if(dp[j++]) {
//                     dp[i] = true;
//                     break;
//                 }
//             }
//         }
//         return dp[0];
//     }
// }

// BFS O(n)
class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        Queue<Integer> q = new LinkedBlockingQueue<>();
        q.add(0);
        int farthest = 0;
        while (!q.isEmpty()) {
            int v = q.poll();
            int j =Math.max(farthest,  v+minJump)
             while(j <= Math.min(v + maxJump, s.length() - 1)){
                if(j>farthest && s.charAt(j)!='1') {
                    q.add(j);
                    if(j==s.length()-1) return true;
                }
                j++;

            }
            farthest = Math.max(farthest, j-1);
        }
        return false;
    }
}