package DS;

class Solution {
    public int minimumOperations(int[] nums) {
        int k=0;
        for(int i=0;i<nums.length;i++){
            int min = Integer.MAX_VALUE;
            for(int j=0;j<nums.length;j++){
                if(nums[j]==0) continue;
                min = Math.min(min,nums[j]);
            }
            if(min==Integer.MAX_VALUE) return k;
            int s=0;
            for(int j=0;j<nums.length;j++){
                if(nums[j]==0) continue;
                nums[j] -=min;
                s += nums[j];
            }
            k++;
            if(s<=0) return k;
        }
        return 0;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] nums = {1,5,0,3,5};
        System.out.println(s.minimumOperations(nums));
    }
}