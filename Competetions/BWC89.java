import java.util.ArrayList;
import java.util.List;

public class BWC89 {
    public int countTime(String time) {
        String[] st = time.split(":");
        String h = st[0];
        String m = st[1];
        int cnt = 0;
        if(h.charAt(1)=='?'){
            if(h.charAt(0)=='?'){
                cnt+=24;
            }
            else{
                if(h.charAt(0)=='2'){
                    cnt+=4;
                }
                else{
                    cnt+=10;
                }
            }
        }
        else{
            if(h.charAt(0)=='?'){
                if(h.charAt(1)<'4'){
                    cnt+=2;
                }
                else{
                    cnt+=1;
                }
            }
            else{
                cnt+=1;
            }
        }
        if(m.charAt(1)=='?'){
            if(m.charAt(0)=='?'){
                cnt*=60;
            }
            else{
                cnt*=10;
            }
        }
        else{
            if(m.charAt(0)=='?'){
                cnt*=6;
            }
            else{
                cnt+=1;
            }
        }
        return cnt;

        
    }
    long modInverse(long a, long m) 
    { 
        long m0 = m; 
        long y = 0, x = 1; 
  
        if (m == 1) 
            return 0; 
  
        while (a > 1) 
        { 
            // q is quotient 
            long q = a / m; 
  
            long t = m; 
  
            // m is remainder now, process same as 
            // Euclid's algo 
            m = a % m; 
            a = t; 
            t = y; 
  
            // Update y and x 
            y = x - q * y; 
            x = t; 
        } 
  
        // Make x positive 
        if (x < 0) 
           x += m0; 
  
        return x; 
    }
    public int[] productQueries(int n, int[][] queries) {
        int i=0;
        int MOD = 1_000_000_007;
        List<Long> powers = new ArrayList<>();
        powers.add(1L);
        while ((n!=0)) {
            int pow = 1<<i;
            if((pow&n)!=0){
                n -=pow; 
                powers.add((long)(1<<i));
            }
            i++;
        }
        long[] prefix = new long[powers.size()];
        prefix[0] = 1;
        for(int j=1;j<prefix.length;j++){
            prefix[j] = (prefix[j-1]*powers.get(j))%MOD;
        }
        int q = queries.length;
        int[] res = new int[q];
        for(int j=0;j<q;j++){
            int l = queries[j][0];
            int r = queries[j][1];
            long ans = prefix[r+1];
            if(l!=0){
                ans = (ans* (prefix[l],MOD))%MOD;
            }
            res[j] = (int)ans;
        }
        return res;
    }
    public int minimizeArrayValue(int[] nums) {
        int n = nums.length;
        int max = nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]) continue;
            int diff = (nums[i]-nums[i-1])/2;
            nums[i] -= diff;
            nums[i-1] += diff;
            max = Math.max(max,nums[i-1]);
        }
        return max;
    }
}
