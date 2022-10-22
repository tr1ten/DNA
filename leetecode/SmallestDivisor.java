class Solution {
    int t;
    boolean ok(int[] arr,int mid){
        int sum = 0;
        for (int x : arr) {
            sum += (int)Math.ceil(x*1.0/mid);
            if(sum>t) return false;
        }
        return sum<=t;
    }
    // generic binary search
    int bs(int[] arr,int lb,int hb){
        int l=lb,h=hb;
        while (l<h) {
            int mid = (l+h)/2;
            if(ok(arr,mid)) h = mid;
            else l=mid+1;
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
    public int smallestDivisor(int[] nums, int threshold) {
        t = threshold;
        return bs(nums, min(nums), max(nums));
    }
}