public class Solution 
{
    public static char kThCharaterOfDecryptedString(String s, Long k) 
    {
        int cur = 0;
        long cnt = 0;
        while(cur<k){
            int i = cur;
            while(i<s.length() && !Character.isDigit(s.charAt(i))){
            i++;
            }
            int j = i;
            String res = "";
            while(i<s.length() && Character.isDigit(s.charAt(i))){
                res += s.charAt(i);
                i++;
            }
            long prev = cnt;
            long num = Long.parseLong(res);
            int len = j-cur;
            if(k<=num || k<=num*(len) || k<=cnt+num || k<=(long)(cnt+num*(len))) return s.charAt(cur+ (int)(k-prev-1)%(j-cur));
            cnt +=num*(len);
            cur = i;
        }
        return 1;
    }
}