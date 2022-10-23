import java.util.Collections;
import java.util.HashMap;

class Solution {
    public int beautySum(String s) {
        int sum = 0;
        int[] map;
        int n = s.length();
        for (int sz=1;sz<=n;sz++) {
            map  =new int[26];
            for (int i = 0; i < sz-1; i++) {
                map[s.charAt(i)-'a']++;
            }
            int i=sz-1;
            while (i<n) {
                map[s.charAt(i)-'a']++;
                int min= Integer.MAX_VALUE;
                int max = Integer.MIN_VALUE;
                for (Integer integer : map) {
                    if(integer==0) continue;
                    min = Math.min(integer, min);
                    max = Math.max(integer, max);
                }
                sum += (max-min);
                i++;
                map[s.charAt(i-sz)-'a']--;
            }
        }
        return sum;
    }
}