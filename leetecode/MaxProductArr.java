public class MaxProductArr {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int max = nums[n-1],min =max;
        int mp = max;
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0){
                if(i<=0) break;
                max = nums[--i];
                min = max;
                mp = Math.max(Math.max(mp,max),0);
            }
            int tmax=max;
            if(nums[i]>0){
                tmax = Math.max(nums[i],nums[i]*max);
                min = Math.min(nums[i],nums[i]*min);
            
            }
            else{
                tmax = Math.max(nums[i],nums[i]*min);
                min = Math.min(nums[i],nums[i]*max);
            }
            max = tmax;
            mp = Math.max(mp,max);
        }
        return Math.max(mp,max);
    }
    public static void main(String[] args) {
        MaxProductArr s = new MaxProductArr();
        int[] nums = new int[]{-2,0,-1};
        System.out.println(s.maxProduct(nums));
    }
}