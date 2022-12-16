import java.util.Arrays;
import java.util.HashMap;

class Solution {
    public int countKDifference(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<>();
        return Arrays.stream(nums).reduce(0,(a,b)->{
            int res = a;
            res +=map.getOrDefault(b+k,0);
            res +=map.getOrDefault(b-k,0);
            map.put(b, map.getOrDefault(b, 0)+1);
            return res;
        });
    }
}