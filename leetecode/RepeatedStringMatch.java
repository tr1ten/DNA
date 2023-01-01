class Solution {
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
    public int strStr(String haystack, String needle) {
        int n=haystack.length();
        int[] lps = prefixArr(needle);
        int i=0,j=0;
        while (i<n) {
            // if equal just move onto next
            if(haystack.charAt(i)==needle.charAt(j)){
                i++;
                j++;
            }
            else{
                // if not equal and j is at start that mean nothing to backtrack
                if(j==0) i++;
                // else backtrack to the last prefix that is also suffix length that will give correct position for next char to iterate
                else j = lps[j-1];
            }
            if(j==needle.length()) return i-needle.length();
        }
        return -1;
    }
    public int repeatedStringMatch(String a, String b) {
        if(a.length()>b.length()) return strStr(a,b)>=0 ? 1 : (strStr(a+a, b)>=0 ? 2 : -1);
        int ind = strStr(b,a);
        if(ind==-1){
            if(strStr(a+a,b)>=0) return 2; 
            return -1;
        }
        if(ind>=a.length()) return -1;
        int i = 0;
        int j=ind;
        int res = ind==0 ? 0 : 1;
        while(j<b.length()){
            if(i==0) res++;
            if(a.charAt(i)!=b.charAt(j)) return -1;
            i = (i+1)%a.length();
            j++;
        }
        return a.endsWith(b.substring(0, ind)) ? res : -1;
    }
}