import java.util.Arrays;

public class WC315 {
    public int findMaxK(int[] nums) {
        Arrays.sort(nums);
        HashSet<Integer> set = new HashSet<>();
        int max = 0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]<0){
                set.add(nums[i]);
            }
            if(nums[i]>max && set.contains(-nums[i])){
                max = nums[i];
            }
        }
        return max;
    }
    public int countDistinctIntegers(int[] nums) {
        HashSet<Integer> set = new HashSet<>();
        for (int i : nums) {
            set.add(i);
            StringBuilder s = new StringBuilder();
            while(i>0){
                s.append(Character.forDigit(i%10, 10));
                i /=10;
            }
            set.add(Integer.valueOf(s.toString()));
            
        }
        return set.size()
    }
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int p1 = 0;
        int p2 = 0;
        long cmin = Integer.MAX_VALUE;
        long cmax = Integer.MIN_VALUE;
        int n = nums.length;
        long cnt = 0;
        int[] cin = new int[n];
        for (int i = n-1; i >=0; i--) {
            if(nums[i]<minK || nums[i]>maxK) cin[i] = -1;
            else{
                if(i<n-1) cin[i] = Math.max(i, cin[i+1]);
                else cin[i] = i;
            }
        }
        while (p2<n) {
            cmax = Math.max(cmax, nums[p2]);
            cmin = Math.min(cmin, nums[p2]);            
            if(cmax==maxK && cmin==minK){
                cnt +=(cin[p1]-p2+1);
                if(nums[p1]==cmin) cmin = Integer.MAX_VALUE;
                if(nums[p1]==cmax) cmax = Integer.MIN_VALUE;
                p1++;
            }
            p2++;

        }
        return cnt;
    }
    boolean ok(int n,int num){
        StringBuilder sb = new StringBuilder(Integer.toString(n)).reverse();
        if((n+Integer.valueOf(sb.toString()))==num) return true;
        return false;
    }
    public boolean sumOfNumberAndReverse(int num) {
        for (int i = 0; i < num; i++) {
            if(ok(i,num)) return true;
        }   
        return false;
    }
}
