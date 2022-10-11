class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int sum = 0;
        int p2 =0;
        int max = Integer.MIN_VALUE;
        while(p2<n){
            sum += nums[p2];
            p2++;
            max = Math.max(max,sum);
            if(sum<0){
                sum =0;
            }
        }
        return max;
    }
}E