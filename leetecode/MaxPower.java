import java.util.*;
public class Solution {
    static class FenwickTree {
        long[] tree;
        public FenwickTree(int[] nums) {
            tree = new long[nums.length+1];
        }
        public void update(int i, long diff) {
            i += 1;
            while (i < tree.length) {
                tree[i] += diff;
                i += i & (-i);
            }
        }
        public long _rangeSum(int i) {
            i += 1;
            long sum = 0;
            while (i > 0) {
                sum += tree[i];
                i -= i & (-i);
            }
            return sum;
        }
        public long rangeSum(int i, int j) {
            return _rangeSum(j) - _rangeSum(i-1);
        }
    }
    public long maxPower(int[] nums, int r, int k) {
        long low = 0;
        long high = (long)Math.pow(10,10);
        while (low < high) {
            long mid = (low+high)/2;
            if (ok(mid, nums, r, k)) low = mid+1;
            else high = mid;
        }
        return low-1;
    }
    public boolean ok(long x, int[] nums, int r, int k) {
        long temp = k;
        FenwickTree acc = new FenwickTree(nums);
        for (int i = 0; i < nums.length; i++) {
            acc.update(i, nums[i]);
        }
        for (int i = 0; i < nums.length; i++) {
            long dff = (long)acc.rangeSum(Math.max(0,i-r),Math.min(nums.length-1,i+r))-x;
            if (dff+temp < 0) return false;
            if (dff < 0) {
                temp += dff;
                acc.update(Math.min(nums.length-1,i+r),-dff);
            }
        }
        return true;
    }
}