import java.util.Arrays;
import java.util.PriorityQueue;

class Solution {
   
    public int eliminateMaximum(int[] dist, int[] speed) {
        PriorityQueue<Double> pq = new PriorityQueue<>();
        for (int i = 0; i < speed.length; i++) {    
            pq.add(dist[i]*1.0/speed[i]);
        }
        int count=0;
        double min=0.0;
        while (!pq.isEmpty() && pq.poll()>min) {
            min +=1.0;
            count++;
        }
        return count;
        
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] dist = {4,3,4};
        int[] speed = {1,1,2};
        System.out.println(sol.eliminateMaximum(dist, speed));
    }
}