import java.util.Arrays;

class Solution {
    public int removeDuplicates(int[] nums) {
        int count = 1;
        int lastEl = nums[0];
        int k = nums.length;
        for (int i = 1; i < nums.length; i++) {
            if(nums[i]==lastEl) count++;
            else count = 1;
            lastEl = nums[i];
            if(count>2) {
                nums[i] = Integer.MAX_VALUE;
                k--;
            }
        }
        Arrays.sort(nums);
        return k;
    }
}