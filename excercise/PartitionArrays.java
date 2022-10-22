import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;

class Solution {
    public int minimumDifference(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        set.add(0);
        long sum =0;
        for (int a:nums) {
            sum+=a;
            for (Integer integer : (HashSet<Integer>)set.clone()) {
                set.add(integer+a);
            }
        }
        long minDiff = Integer.MAX_VALUE;
        for (long integer : set) {
            minDiff = Math.min( Math.abs(sum - integer - integer), minDiff);
        }
        return (int)minDiff;
    }
}