import java.util.HashMap;

class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        int sum = 0;
        hm.put(0,-1);
        for(int i=0;i<nums.length;i++){
            int x = nums[i];
            sum +=x;
            int mod = sum%k;
            if(hm.containsKey(mod) && (i-hm.get(mod))>1) return true;
            else if(!hm.containsKey(mod)) hm.put(mod, i);
        }
        return false;
    }
}