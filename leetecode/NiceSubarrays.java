class Solution {
    public int numberOfSubarrays(int[] nums, int k) {
        // generic window method
        int cnt = 0;
        int j = 0;
        int res = 0;
        int n = nums.length;
        int[] lefty = new int[n];
        int[] righty = new int[n];
        int li = -1;
        int ri = n;
        for (int i = 0; i < n; i++) {
            lefty[i] = li;
            righty[n-i-1] = ri;
            if((nums[i]&1)==1) li = i;
            if((nums[n-i-1]&1)==1) ri = n-i-1;
        }
        for(int i=0;i<n;i++){
            if((nums[i]&1)==1) cnt++;
            if(cnt==k){
                int left =0;
                while(j<i && cnt==k){
                    left++;
                    if((nums[j]&1)==1) cnt--;
                    j++;
                }
                res += (righty[i]-i)*(left);
            }
        }
        return res;
    }
}