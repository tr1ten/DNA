import java.util.HashMap;
import java.util.HashSet;

import javax.lang.model.type.ErrorType;
// Out of memory lmao
// class Solution {
//     HashMap<Character,HashSet<Character>> hm;
//     Integer[][] dp;
//     HashMap<Integer,Integer> map;
//     static int MOD = 1_000_000_007;
//     long solve(int n,String s){
//         int sn = s.length();
//         if(n==0) return 1;
//         int key = sn>0 ? map.get(s.charAt(sn-1) -'a'): 5;
//         if(dp[n][key]!=null) return dp[n][key]; 
//         long cnt = 0; 
//         for (Character x:hm.keySet()) {
//             if(s.isEmpty() || hm.get(s.charAt(sn-1)).contains(x)) cnt = (cnt + solve(n-1, s+x))%MOD;
//         }
//         dp[n][key] = (int)cnt;
//         return cnt;
//     }
//     public int countVowelPermutation(int n) {
//         hm = new HashMap<>();
//         dp = new Integer[n+1][6];
//         map = new HashMap<>();
//         map.put(0,0);
//         map.put('e'-'a',1);
//         map.put('i'-'a',2);
//         map.put('o'-'a',3);
//         map.put('u'-'a',4);
//         hm.put('a',new HashSet<>());
//         hm.put('e',new HashSet<>());
//         hm.put('i',new HashSet<>());
//         hm.put('o',new HashSet<>());
//         hm.put('u',new HashSet<>());
//         hm.get('a').add('e');
//         hm.get('e').add('a');
//         hm.get('e').add('i');
//         hm.get('i').add('a');
//         hm.get('i').add('e');
//         hm.get('i').add('o');
//         hm.get('i').add('u');
//         hm.get('o').add('i');
//         hm.get('o').add('u');
//         hm.get('u').add('a');
//         return (int)solve(n, "");
//     }
// }

class Solution {
    static int MOD = 1_000_000_007;
    public int countVowelPermutation(int n) {
        int[][] mm = {
            {0,1,0,0,0},
            {1,0,1,0,0},
            {1,1,0,1,1},
            {0,0,1,0,1},
            {1,0,0,0,0}
        };
        Long[][] dp = new Long[5][n+1];
        for(int i=0;i<5;i++) dp[i][1] = 1L;
        for(int i=2;i<=n;i++){
            for(int j=0;j<5;j++){
                dp[j][i] = 0L;
                for (int j2 = 0; j2 < 5; j2++) {
                    dp[j][i]  =  (dp[j][i]  + dp[j2][i-1]*mm[j2][j])%MOD;
                }
            }
        }
        long sum = 0;
        for(int i=0;i<5;i++) sum = (sum+dp[i][n])%MOD;
        return (int)sum;
        
    }
}