package DS;

class MinSSS {
    public int minSubArrayLen(int target, int[] nums) {
        int n = nums.length;
        int i=0;
        int j=0;
        int c = 0;
        int mn=Integer.MAX_VALUE;

        while(j<=n){
            if(c>=target){
                c -= nums[i];
                mn = Math.min(mn,j-i);
                i++;
            }
            else{
                if(j<n) c +=nums[j++];
                else break;
            }
        }
        return mn==Integer.MAX_VALUE?0:mn;
    }
    public static void main(String[] args) {
        MinSSS s = new MinSSS();
        System.out.println(s.minSubArrayLen(7, new int[]{2,3,1,2,4,3}));
    }
}