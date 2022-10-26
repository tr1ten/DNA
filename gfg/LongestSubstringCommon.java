import java.util.Arrays;

class Solution {
    static int lps(String a,String b){
        int i =0;
        int sz = Math.min(a.length(), b.length());
        while (i<sz) {
            if(a.charAt(i)!=b.charAt(i)) return i;
            i++;
        }
        return i;
    }
    static String longestSubstring(String S, int N) {
        String[] suffixArray = new String[N];
        String s = "";
        for (int i = 0; i <N; i++) {
            suffixArray[i] = S.substring(i,N);
        }
        Arrays.sort(suffixArray);
        int rs = 0;
        String lrs = "";
        for (int i = 0; i < N-1; i++) {
            int len = lps(suffixArray[i], suffixArray[i+1]);
            if(len>lrs.length()){
                lrs = suffixArray[i].substring(0,len);
                rs = Math.max(suffixArray[i].length(), suffixArray[i+1].length());
            }
            else if(len==lrs.length() && Math.max(suffixArray[i].length(), suffixArray[i+1].length())>rs){
                lrs = suffixArray[i].substring(0,len);
                rs = Math.max(suffixArray[i].length(), suffixArray[i+1].length());
            }
        }
        return lrs.length()==0 ? "-1" : lrs;
    }
};