import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.stream.IntStream;

class Solution {
    public int[] getOrder(int[][] A) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->Integer.compare(A[a][1],A[b][1]));
        int time = 0;
        Integer[] ss = IntStream.range(0,A.length).boxed().toArray(Integer[]::new);
        Arrays.sort(ss,(a,b)->Integer.compare(A[a][0],A[b][0]));
        int k = 0;
        int[] res = new int[A.length];
        for(int j=0;j<A.length;j++){
            if(pq.isEmpty()) time = Math.max(time,A[ss[j]][0]);
            while(j<A.length && A[ss[j]][0]<=time) pq.offer(ss[j++]);
            if(!pq.isEmpty()){
                int temp = pq.poll();
                res[k++] = temp;
                time = A[temp][0] + A[temp][1];
            }
            
        }
        return res;
    }
}