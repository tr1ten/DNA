package Algos;
// Hard to understand but O(n) solution
public class KMP {
    // longest prefix that is also suffix length array
    int[] prefixArr(String needle){
        int m = needle.length();
        // prefix cannot be overlapping with suffix
        int len=0,i=1;
        int[] lps = new int[m];
        while (i<m) {
            if(needle.charAt(i)==needle.charAt(len)){
                lps[i++] = ++len;
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
    public static void main(String[] args) {
        KMP s = new KMP();
        System.out.println(s.strStr("onionionsp", "onions"));
    }
}
