import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class FourSum {
    private Set<ArrayList<Integer>> sols;
    private void rec(int cur,ArrayList<Integer> path,int[] nums,int idx,int target){
        if(path.size()==2){
            // use two pouinter method
            int i=idx,j=nums.length-1;
            while(i<j){
                // prevent overflow
                int num = nums[i]+nums[j];
                if((num>0 && cur>Integer.MAX_VALUE-num) || (num<0 && cur<Integer.MIN_VALUE-num)){
                    i++;
                    continue;
                }
                int sum =cur + nums[i]+nums[j];
                if(sum==target){

                    ArrayList<Integer> sol = new ArrayList<>(path);
                    sol.add(nums[i]);
                    sol.add(nums[j]);
                    sols.add(sol);
                    i++;
                    j--;
                }else if(sum<target){
                    i++;
                }else{
                    j--;
                }
            }
        }
        if(idx>=nums.length) return;
        rec(cur,path,nums,idx+1,target);
        ArrayList<Integer> temp = (ArrayList<Integer>) path.clone();
        temp.add(nums[idx]);
        rec(cur+nums[idx],temp,nums,idx+1,target);
    }
    public List<List<Integer>> fourSum(int[] nums, int target) {
        if(nums.length<4) return new ArrayList<>();
        sols = new HashSet<>();
        Arrays.sort(nums);
        rec(0,new ArrayList<Integer>(),nums,0,target);
        return new ArrayList<>(sols);   
    }
    public static void main(String[] args) {
//         [1000000000,1000000000,1000000000,1000000000]
// -294967296

        FourSum fs = new FourSum();
        int[] nums = {1000000000,1000000000,1000000000,1000000000};
        System.out.println(fs.fourSum(nums,-294967296));
    }
}