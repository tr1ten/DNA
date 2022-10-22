import java.util.Deque;
import java.util.TreeMap;
import java.util.concurrent.LinkedBlockingDeque;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] res = new int[nums.length-k+1];
        TreeMap<Integer,Integer> pq = new TreeMap<>((a,b)->b-a);
        for (int i = 0; i < k; i++) {
            pq.put(nums[i],pq.getOrDefault(nums[i], 0)+1);
        }
        int i=k;
        while (i<nums.length) {
            res[i-k] = pq.firstKey();
            if(pq.get(nums[i-k])>1) pq.put(nums[i-k], pq.get(nums[i-k])-1);
            else pq.remove(nums[i-k]);
            pq.put(nums[i],pq.getOrDefault(nums[i], 0)+1);
            i++;
        }
        res[i-k] = pq.firstKey();
        return res;
    }
}

class Solution2 {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] res = new int[nums.length-k+1];
        Deque<Integer> st = new LinkedBlockingDeque<>();
        int i=0;
        for (; i < nums.length; i++) {
            if(i>=k){
                while (!st.isEmpty() && (i-st.peekLast())>k) {
                    st.removeLast();
                }
                res[i-k] = nums[st.peekLast()];
            
            }
            if(st.isEmpty() || nums[st.peekLast()]<=nums[i]) {
                st.addLast(i);

            }
            else{
                while (nums[st.getFirst()]<=nums[i]) {
                    st.removeFirst();
                }
                st.addFirst(i);
            }
        }
        while (!st.isEmpty() && (i-st.peekLast())>k) {
            st.removeLast();
        }
        res[nums.length-k] = nums[st.peekLast()];
        return res;
    }
}