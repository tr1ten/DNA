class Solution {
    int atmostK(int[] nums,int k){
        int i=0;
        int n = nums.length;
        int mxsz = 0;
        for(int j=0;j<n;j++){
            if(nums[j]==0) k--;
            while(k<0){
                if(nums[i]==0) k++;
                i++;
            }
            mxsz = Math.max(j-i+1,mxsz);
            
        }
        return mxsz;
    }
    public int longestOnes(int[] nums, int k) {
        return atmostK(nums,k);
    }
}