class Solution {
    int[] costs;
    int bs(int[] arr,int lb,int hb){
        int l=lb,h=hb;
        while (l<h) {
            int mid = (l+h)/2;
            if(fn(arr,mid)>fn(arr, mid+1)) l = mid+1;
            else h=mid;
        }        
        return h;
    }   
    static int min(int... a){
        int min = Integer.MAX_VALUE;
        for(int i=0;i<a.length;i++){
            if(a[i]<min)
                min = a[i];
        }
        return min;
    }
    static int max(int... a){
        int max = Integer.MIN_VALUE;
        for(int i=0;i<a.length;i++){
            if(a[i]>max)
                max = a[i];
        }
        return max;
    }
    public long fn(int[] nums, int tar){
        long ans = 0;
        for(int i = 0; i<nums.length; i++){
            if(nums[i] != tar){
                int diff = Math.abs(nums[i] - tar); 
                ans+=(long) diff*costs[i];
            }
        }
        return ans;
    }
    public long minCost(int[] nums, int[] cost) {
        costs = cost;
        return fn(nums,bs(nums, min(nums), max(nums)));
    }
        
}