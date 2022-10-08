import java.util.HashMap;
import java.util.HashSet;

class Solution {
    HashMap<HashSet<String>,Boolean> dp;
    boolean solve(String s1,int p1, String s2, int p2, String s3,int p3){
        int n1 = s1.length();
        int n2 = s2.length();
        if((n1-p1) + (n2-p2)!=(s3.length()-p3)) return false;
        HashSet<String> key = new HashSet<>();
        key.add(s1.substring(p1,n1));
        key.add(s2.substring(p2,n2));
        if(dp.containsKey(key)) return dp.get(key); 
        for(int i=p3;i<s3.length();i++){
            char x= s3.charAt(i);
            if(p1<n1 && p2<n2 && s1.charAt(p1)==x && s2.charAt(p2)==x) {
                 dp.put(key, solve(s1, p1, s2, p2+1, s3, i+1) || solve(s1, p1+1, s2, p2, s3, i+1));
                    return dp.get(key);
                }
            if(p1<n1 && s1.charAt(p1)==x) p1++;
            else if (p2<n2 && s2.charAt(p2)==x) p2++;
            else break;
        }
        boolean ans = p1==n1 && p2==n2;
        dp.put(key, ans);
        return ans;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        dp = new HashMap<>();
        return solve(s1, 0, s2, 0, s3, 0);
    }
}