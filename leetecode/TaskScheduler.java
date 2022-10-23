import java.util.HashMap;
import java.util.TreeMap;

class Solution {
    static int max(int... a){
        int max = Integer.MIN_VALUE;
        for(int i=0;i<a.length;i++){
            if(a[i]>max)
                max = a[i];
        }
        return max;
    }
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        int n_e = tasks.length;
        for(char x:tasks){
            map[x-'A']++;
        }
        int max = max(map);
        int cnt = 0;
        for (int i : map) {
            if(i==max) cnt++;
        }
        return Math.max((max-1)*(n+1)+cnt, tasks.length);
    }
}