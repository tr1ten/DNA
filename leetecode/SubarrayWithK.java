import java.util.HashMap;

class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
        HashMap<Integer,Integer> cnt = new HashMap<>();
        int j = 0;
        int res = 0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            cnt.put(nums[i],cnt.getOrDefault(nums[i], 0)+1);
            if(cnt.size()==k){
                int left =0;
                int right = 0;
                for(int m=i;m<n;m++){
                    if(!cnt.containsKey(nums[m])) break;
                    right++;
                }
                while(j<=i && cnt.size()==k){
                    left++;
                    if(cnt.get(nums[j])==1) cnt.remove(nums[j]);
                    else cnt.put(nums[j],cnt.get(nums[j])-1);
                    j++;
                }
                res += (right)*(left);
            }
        }
        return res;
    }
}