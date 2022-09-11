import java.util.*;
class Solution {
    private void sub(List<ArrayList<Integer>> res,int idx,int[] nums,ArrayList<Integer> arr){
        
        if(idx>=nums.length) {
            ArrayList<Integer> temp = (ArrayList<Integer>)arr.clone();
            res.add(temp);
        }
        arr.add(nums[idx]);
        sub(res,idx+1,nums,arr);
        arr.remove(arr.size()-1);
        while(idx+1<nums.length && nums[idx]==nums[idx+1]) idx++;
        sub(res,idx+1,nums,arr);
        
    }
    public List<ArrayList<Integer>> subsetsWithDup(int[] nums) {
        List<ArrayList<Integer>> hs = new ArrayList<ArrayList<Integer>>();
        Arrays.sort(nums);
        sub(hs,0,nums,new ArrayList<Integer>());
        return hs;
    }
}