package Competetions;

import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.TreeMap;

public class Solution {
    public int mostFrequentEven(int[] nums) {
        HashMap<Integer,Integer> tm = new HashMap<>();
        for(int i:nums){
            if(i%2==0){
                if(!tm.containsKey(i)) tm.put(i, 1);
                else tm.put(i, tm.get(i)+1);
            }
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]==b[0] ? a[1]-b[1] : b[1]-a[1] );
        for (int k :tm.keySet()) {
            pq.add(new int[]{tm.get(k),k});
        }
        return pq.poll()[1];
    }
    public int partitionString(String s) {
        int n = s.length();
        HashMap<Character,Integer> hm = new HashMap<>();
        for (char c:s.toCharArray()) {
            if(hm.containsKey(c)) hm.put(c, hm.get(c)+1);
            else hm.put(c, 1);
            
        }
        int m = 0;
        for (var entry : hm.entrySet()) {
            m = Math.max(entry.getValue(), m);
        }
        return m;
    }

    public int minGroups(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->a[0]==b[0] ? a[1]-b[1] : a[0]-b[0]);
        int ans = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int[] is : intervals) {
            while(!pq.isEmpty() && pq.peek()<is[0]) pq.poll();
            pq.add(is[1]);
            ans = Math.max(ans, pq.size());
        }
        return ans;   
    }
}
