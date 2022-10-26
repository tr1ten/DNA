import java.util.Collection;
import java.util.Collections;
import java.util.TreeMap;

class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        TreeMap<Integer,Integer> ts = new TreeMap<>();
        int res=0;
        for(int i=0;i<n;i++){
            Integer lb = ts.lowerKey(nums[i]);
            if(lb==null) ts.put(nums[i], 1);
            else ts.put(nums[i], ts.get(lb)+1); 
        }
        return Collections.max(ts.values());
    }
}