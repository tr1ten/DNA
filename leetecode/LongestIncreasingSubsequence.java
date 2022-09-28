import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class LongestIncreasingSubsequence {
    int lower(List<Integer> dp,int val){
        int left = 0;
        if(dp.size() == 0){
            return 0;
        }
        int right = dp.size()-1;
        while(left+1 < right){
            int mid = left + (right-left)/2;
            if(dp.get(mid) == val){
                return mid;
            }
            else{
                if(dp.get(mid) < val){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
        }
        if(dp.get(right) < val) return dp.size();
        else if(dp.get(left) >= val) return left;
        else return right;
    }
    public int lengthOfLIS(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            int ind = lower(res,nums[i]);
            if(ind >= res.size()){
                res.add(nums[i]);
            }
            else{
                res.set(ind,nums[i]);
            }
        }
        return res.size();
    }
    public static void main(String[] args) {
        LongestIncreasingSubsequence sol = new LongestIncreasingSubsequence();
        int[] nums = {10,9,2,5,3,7,101,18};
        System.out.println("nums: " + Arrays.toString(nums));
        int res = sol.lengthOfLIS(nums);
        System.out.println("res: " + res);

    }
}