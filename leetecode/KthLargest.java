package leetecode;
import java.util.*;

public class KthLargest {
    PriorityQueue<Integer> pq;
    int k;
    public KthLargest(int k, int[] nums) {
        this.k = k;
        pq = new PriorityQueue<>();
        Arrays.sort(nums);
        for (int i = nums.length - k-1; i < nums.length; i++) {
            pq.add(nums[i]);
        }
        if(nums.length>=k)
        {
            pq.add(nums[nums.length-k]);
        }
    }
    
    public int add(int val) {
        if(pq.size()<k)
        {
            pq.add(val);
            return pq.peek();
        }
        if(val<=pq.peek())
        {
            return pq.peek();
        }
        pq.add(val);
        pq.remove();
        return pq.peek();

    }
}
