class Solution {
    int atmostK(int[] nums,int k){
        int i=0;
        int n = nums.length;
        HashMap<Integer,Integer> map = new HashMap<>();
        int mxsz = 0;
        for(int j=0;j<n;j++){
            if(map.getOrDefault(nums[j],0)==0) k--;
            map.put(nums[j],map.getOrDefault(nums[j],0)+1);
            while(k<0){
                map.put(nums[i],map.getOrDefault(nums[i],0)-1);
                if(map.getOrDefault(nums[i],0)==0) k++;
                i++;
            }
            mxsz = Math.max(j-i+1,mxsz);
            
        }
        return mxsz;
    }
    public int totalFruit(int[] fruits) {
        return atmostK(fruits,2);
    }
}