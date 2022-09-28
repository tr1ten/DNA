import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> goodIndices(int[] nums, int k) {
        int n = nums.length;
        int[] inc = new int[n];
        int[] dec = new int[n];
        dec[0] = 1;
        for (int i = 1; i <n; i++) {
            dec[i] = 1;
            if(nums[i]<nums[i-1]) dec[i] +=dec[i-1];
        }
        inc[n-1] = 1;
        for (int i = n-2; i >=0; i++) {
            inc[i] = 1;
            if(inc[i+1]>inc[i]) inc[i] +=inc[i+1];
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i < n-1; i++) {
            if(inc[i+1]>=k || dec[i-1]>=k) res.add(i);
        }
        return res;

    }
}