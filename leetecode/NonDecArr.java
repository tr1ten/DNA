class Solution {
    public boolean checkPossibility(int[] nums) {
        int n = nums.length;
        if(n<2) return true;
        int p1=0;
        int p2 = 1;
        int last = -100001;
        int chance =1;
        while(p2<n){
            if(nums[p2]<nums[p1]) {
                if(chance<=0) return false; 
                if(nums[p2]>=last) nums[p1] = nums[p2];
                else nums[p2] = nums[p1];
                chance--;
            }
            last = nums[p1];
            p1++;
            p2++;
        }
        return true;
    }
}