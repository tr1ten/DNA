import java.util.*;
import java.util.function.Supplier;;
class Solution {
    public double[] medianSlidingWindow(int[] nums, int k) {
        PriorityQueue<Integer> mxpq = new PriorityQueue<>((a,b)->Integer.compare(nums[b], nums[a]));
        PriorityQueue<Integer> mnpq = new PriorityQueue<>((a,b)->Integer.compare(nums[a], nums[b]));
        int n = nums.length;
        // first pq is always eq or 1 greator than second
        for (int j = 0; j < Math.min(n, k); j++) {
            int x = nums[j];
            if(mxpq.isEmpty()) mxpq.offer(j);
            else if(x<nums[mxpq.peek()]){
                if(mxpq.size()==mnpq.size()) mxpq.offer(j);
                else{
                    mnpq.offer(mxpq.poll());
                    mxpq.offer(j);
                }
            }
            else{
                if(mnpq.size()<mxpq.size()) mnpq.offer(j);
                else if(x>nums[mnpq.peek()]) {
                    mxpq.offer(mnpq.poll());
                    mnpq.offer(j);
                }
                else mxpq.offer(j);
            }
        }
        int i = 0;
        ArrayList<Double> res = new ArrayList<>();
        if(mxpq.size()==mnpq.size()) res.add((nums[mxpq.peek()]*1L+nums[mnpq.peek()]*1L)*1.0/2);
        else res.add(nums[mxpq.peek()]*1.0);
        for(int j=k;j<n;j++){ // tricky part is here, when both can be shorter than each other
            int x = nums[j];
            if(mnpq.remove(i)){ // second pq will be shorter now, so we will try to increase its second to be eq to first
                if(x<nums[mxpq.peek()]){
                    mnpq.offer(mxpq.poll());
                    mxpq.offer(j);
                }
                else mnpq.offer(j);
            }
            else { // either first pq will be smaller or equal now
                mxpq.remove(i);
                if(mxpq.isEmpty() && mnpq.isEmpty()) mxpq.offer(j);
                else if(x>nums[mnpq.peek()]) {
                    mxpq.offer(mnpq.poll());
                    mnpq.offer(j);
                }
                else mxpq.offer(j);
                
            }
            i +=1;
            if(mxpq.size()==mnpq.size()) res.add((nums[mxpq.peek()]*1L+nums[mnpq.peek()]*1L)*1.0/2);
            else res.add(nums[mxpq.peek()]*1.0);
        }
        return res.stream().mapToDouble(arg->arg).toArray();
    }
}

// best solution
class Solution2 {
    public double[] medianSlidingWindow(int[] nums, int k) {
    Comparator<Integer> comparator = (a, b) -> nums[a] != nums[b] ? Integer.compare(nums[a], nums[b]) : a - b;
    TreeSet<Integer> left = new TreeSet<>(comparator.reversed());
    TreeSet<Integer> right = new TreeSet<>(comparator);
    
    Supplier<Double> median = (k % 2 == 0) ?
        () -> ((double) nums[left.first()] + nums[right.first()]) / 2 :
        () -> (double) nums[right.first()];
    
    // balance lefts size and rights size (if not equal then right will be larger by one)
    Runnable balance = () -> {
            while ((left.size() > right.size())) right.add(left.pollFirst()); 
        };
    
    double[] result = new double[nums.length - k + 1];
    
    for (int i = 0; i < k; i++) left.add(i);
    balance.run(); result[0] = median.get();
    
    for (int i = k, r = 1; i < nums.length; i++, r++) {
        // remove tail of window from either left or right
        if(!left.remove(i - k)) right.remove(i - k);

        // must add next num to right, this will always increase left size
        right.add(i); // eg [1] [3,4] now if A[i]=6 then we first need to shift element from right to left then balance the length
        left.add(right.pollFirst());
        
        // rebalance left and right, then get median from them
        balance.run(); result[r] = median.get();
    }
    
    return result;
}
}