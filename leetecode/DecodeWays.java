

import java.util.HashMap;
import java.util.HashSet;

public class DecodeWays {
    HashSet<String> hs;
    HashMap<Integer,Integer> hm;

    private int rec(int i, String s) {
        int n = s.length();
        if (i >= n) {
            return 1;
        }
        if(hm.containsKey(i)) return hm.get(i);
        int total = 0;
        if (i < (n - 1) && hs.contains(s.substring(i, i + 2))) {
            total +=rec(i + 2, s);
        }
        if (hs.contains(s.substring(i, i + 1))) {
            total += rec(i + 1, s);
        }
        hm.put(i,total);
        return total;
    }

    public int numDecodings(String s) {
        hs = new HashSet<>();
        hm = new HashMap<>();
        for (int i = 1; i <= 27; i++) {
            hs.add(Integer.toString(i));
        }
        return  rec(0, s);
    }

    public static void main(String[] args) {
        DecodeWays decodeWays = new DecodeWays();
        System.out.println(decodeWays.numDecodings("11"));
    }

}
