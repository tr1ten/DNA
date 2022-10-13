import java.util.HashMap;

class Solution {
    
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> diff = new HashMap<>();
        int sum = 0;
        int cnt = 0;
        diff.put(0,1);
        for(int x:nums){
            sum +=x;
            int d = sum-k;
            cnt += diff.getOrDefault(d,0);
            diff.put(sum, diff.getOrDefault(sum, 0)+1);
        }
        return cnt;
    }
}