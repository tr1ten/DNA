class Solution {
    int[] buckets;
    int res;
    void solve(int idx,int[] nums){
        int n = nums.length,k = buckets.length;
        if(idx==n){
            int mx = Integer.MIN_VALUE;
            for(int x:buckets){
                mx = Math.max(mx,x); 
            }
            res = Math.min(mx,res);
            return;
        }
        for(int i=0;i<k;i++){
            if(buckets[i]+nums[idx]<res){
                buckets[i] += nums[idx];
                solve(idx+1,nums);
                buckets[i] -= nums[idx];
            }
        }
    }
    public int distributeCookies(int[] nums, int k) {
        buckets = new int[k];
        res = 1_000_000;
        solve(0,nums);
        return res;
        
    }
}