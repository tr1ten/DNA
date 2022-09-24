class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        if(n==1) return 0;
        int h = n-1;
        int l = 0;
        int mid=0;
        while(l<=h){
            mid = (l+h)/2;
            if(mid==0){
                if(nums[mid+1]<nums[mid]) return 0;
                l = mid+1;
                continue;
            }
            if(mid==n-1){
                if(nums[mid-1]<nums[mid]) return mid;
                h = mid-1;
                continue;
            }
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                l = mid+1;
            }
               else{
                h = mid-1;
            }
        }
        return mid;
    }
               
}
    