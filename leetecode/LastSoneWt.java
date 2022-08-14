import java.util.PriorityQueue;

public class LastSoneWt {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->b-a);
        for (int x:stones) {
            pq.add(x);
        }
        while (pq.size()>1){
            int y = pq.remove();
            int x = pq.remove();
            if(x!=y) pq.add(y-x);
        }
        return pq.isEmpty() ? 0: pq.remove();
    }
}
