import java.util.Arrays;

class Solution {
    int t;
    int days;
    boolean ok(int[] arr,int shipWt){
        int tw = 0;
        int i =0;
        int d = days;
        while (i<arr.length) {
            tw += arr[i];
            if(tw>shipWt){
                d--;
                tw = 0;
            }
            else{
                i++;
            }
        }
        return d>0;
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
    static int max(int... a){
        int max = Integer.MIN_VALUE;
        for(int i=0;i<a.length;i++){
            if(a[i]>max)
                max = a[i];
        }
        return max;
    }
    static int sum(int ...a){
        int sum = 0;
        for(int i=0;i<a.length;i++){
            sum+=a[i];
        }
        return sum;
    }
    public int shipWithinDays(int[] weights, int days) {
        Arrays.sort(weights);
        this.t = sum(weights);
        this.days = days;
        return bs(weights, max(weights), t);
    }
}