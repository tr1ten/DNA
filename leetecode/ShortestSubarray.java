class Something {
    public int shortestSubarray(int[] nums, int k) {
        int min = Integer.MAX_VALUE;
        int n = nums.length;
        int lastj = 1;
        int sum = nums[0];
        for(int i=0;i<n;i++){
            int j = lastj;
            if(sum<k) 
            {
                for(;j<n;j++){
                    if(sum>=k) break;
                    sum +=nums[j];
                }
                lastj = j;
            }
            if(sum>=k) min = Integer.min(min,j-i);
            sum -= nums[i];
        }
        return min==Integer.MAX_VALUE ? -1 : min;
    }
    public static void main(String[] args) {
        Something s = new Something();
        int[] nums = {2,-1,2};
        int k = 3;
        System.out.println(s.shortestSubarray(nums,k));
    }
}