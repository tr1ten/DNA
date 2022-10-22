import java.util.*;;
class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        Integer[] sortedKeys = new Integer[n];
        for (int i = 0; i < sortedKeys.length; i++) sortedKeys[i] = i;
        Arrays.sort(sortedKeys,(a,b)->capital[a]-capital[b]);
        int[] sortedProfits = new int[n];
        int[] sortedCapital = new int[n];
        int i=0;
        for (int key:sortedKeys) {
            sortedCapital[i] = capital[key];
            sortedProfits[i] = profits[key];
            i++;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b)->b-a);
        i=0;
        while (k-->0) {
            while (i<sortedCapital.length) {
                if(sortedCapital[i]>w) break;
                pq.add(sortedProfits[i]);
                i++;
            }
            w += pq.poll();
        }
        return w;
    }
}