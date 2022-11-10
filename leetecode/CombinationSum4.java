import java.util.HashMap;

class Solution {
    
    int solve(int idx,int sum,HashMap<Integer,Integer> cnt,int[] nums,int target){
        // need to return all possible combinations count
        if(sum==target) {
            return ?;
        }
        if(sum>target) return 0;
        int res=0;
        for(int i=idx;i<nums.length;i++){
            cnt.put(nums[i],cnt.getOrDefault(nums[i],0)+1);
            res += solve(i,sum+nums[i],cnt,nums,target);
            if(cnt.get(nums[i])==1) cnt.remove(nums[i]);
            else cnt.put(nums[i],cnt.getOrDefault(nums[i],0)-1);
            

        }
        return res;
        
    }
    public int combinationSum4(int[] nums, int target) {
        Arrays.sort(nums);
        return solve(0,0,new HashMap<>(),nums,target);
    }
}