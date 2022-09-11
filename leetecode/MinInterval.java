import java.util.Arrays;
import java.util.HashMap;
import java.util.PriorityQueue;
import java.util.Stack;

class Solution {
    public int[] minInterval(int[][] intervals, int[] queries) {
        Arrays.sort(intervals,(a,b)->a[0]==b[0] ? a[1]-b[1] : a[0]-b[0]);
        HashMap<Integer,Stack<Integer>> hm = new HashMap<>();
        for (int i = 0; i < queries.length; i++) {
            if(hm.get(queries[i])){
                hm.put(queries[i], hm.get(queries[i]).push(i));
                continue;
            }
            Stack<Integer> st = new Stack<>();
            st.push(i);
            hm.put(queries[i],st);
        }
        Arrays.sort(queries);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]==b[0] ? a[1]-b[1] : a[0]-b[0]);
        int[] res = new int[queries.length];
        int i =0;
        int k=0;
        for (int q:queries) {
            while(!pq.isEmpty() && pq.peek()[1]<q) pq.poll();
            while(i<intervals.length && intervals[i][0]<=q) {
                pq.offer(new int[]{intervals[i][1]-intervals[i][0]+1,intervals[i][1]});
                i++;
            }
            if(pq.isEmpty()) res[hm.get(q).pop()] = -1;
            else res[hm.get(q).pop()] = pq.peek()[0];
        }
    return res;
    }
}