import java.util.HashMap;
/**
 * MinimumWindowSubstring
 */
public class MinimumWindowSubstring {
    public String minWindow(String s, String t) {
        int sn = s.length();
        int tn = t.length();
        int[] hm = new int[64];
        boolean[] hs = new boolean[64];
        
        for (char c : t.toCharArray()) {
            hm[c-'A'] +=1;
            hs[c-'A'] = true;
        }
        int start = 0;
        int min = sn;
        int k =tn;
        int j = 0;
        for (int i = 0; i <= sn-tn; i++) {
            if(!hs[s.charAt(i)-'A']) continue;
            if(j<i) j =i;
            for (; j < sn && k>0; j++) {
                int key = s.charAt(j) - 'A';
                if(hs[key]) {
                    hm[key]--;
                    if(hm[key]>=0) k--;
                }
            }
            if(j-i+ 1<min && k==0) {
                start = i;
                min = j-i+1;
            }
            if(++hm[s.charAt(i)-'A']>0) k++;
        
        }
        return s.substring(start,start+min-1);

    }
    public static void main(String[] args) {
        MinimumWindowSubstring mws = new MinimumWindowSubstring();
        System.out.println(mws.minWindow("ABSXCOCASBA", "ABC"));
    }
}