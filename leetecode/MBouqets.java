class Solution {
    int m;
    int k;
    // generic ok function signature
    boolean ok(int[] arr,int mid){
        int cnt=k;
        int bqs=0;
        for(int d:arr){
            if(d<=mid) cnt--;
            else cnt=k;
            if(cnt==0) {
                bqs++;
                cnt=k;
            }
            if(bqs==m) return true;
        }
        return bqs==m;
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
    public int minDays(int[] bloomDay, int m, int k) {
        if(Long.compare((long)m*k,bloomDay.length)>0) return -1;
        this.m = m;
        this.k=k;
        return bs(bloomDay, min(bloomDay), max(bloomDay));
    }
}