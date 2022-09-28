public class Solution {
    int[] prefixArr(String needle){
        int m = needle.length();
        // prefix cannot be overlapping with suffix
        int len=0,i=1;
        int[] lps = new int[m];
        while (i<m) {
            if(needle.charAt(i)==needle.charAt(len)){
                lps[i] = len+1;
                len++;
                i++;
            }
            else if(len==0) lps[i++] = 0;
            else len = lps[len-1];
        }
        return lps;
    }
    public int solve(String A) {
        return A.length() - prefixArr(A+"0"+new StringBuilder(A).reverse().toString())[2*A.length()];
    }
}
