class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums); // greedy
        int i = 0;
        int res=1;
        for(int j=0;j<nums.length;j++){
            if(nums[j]-nums[i]>k){
                res++;
                i = j;
            }
        }
        
        return res;
    }
}