import java.util.Arrays;
import java.util.HashMap;

public class WC316 {
    public boolean haveConflict(String[] event1, String[] event2) {
        String[] e1s = event1[0].split(":");
        String[] e1e = event1[1].split(":");
        String[] e2s = event2[0].split(":");
        String[] e2e = event2[1].split(":");
        int e1start = Integer.parseInt(e1s[0])*60 + Integer.parseInt(e1s[1]);
        int e1end = Integer.parseInt(e1e[0])*60 + Integer.parseInt(e1e[1]);
        int e2start = Integer.parseInt(e2s[0])*60 + Integer.parseInt(e2s[1]);
        int e2end = Integer.parseInt(e2e[0])*60 + Integer.parseInt(e2e[1]);
        // check overlapping
        if(e1start<=e2start){
            return e2start<=e1end;
        }
        else{
            return e1start<=e2end;
        }
    }
    HashMap<Set<Integer>, Integer> map;
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    public int subarrayGCD(int[] nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.length; i++) {
            int g = nums[i];
            for (int j = i; j < nums.length; j++) {
                g = gcd(g,nums[j]);
                if(g%k==0) ans++;
            }
        }
        return ans;
    }
    
    

}
