import java.util.HashSet;

class Solution {
    public String longestPrefix(String s) {
        int n =s.length();
        HashSet<Long> prefix = new HashSet();
        int p = 31;
        int m = 1_000_000_009;
        long hash_value = 0;
        long p_pow = 1;
        for(int j=0;j<n-1;j++){

            hash_value = (hash_value + (s.charAt(j) - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
            prefix.add(hash_value);
        }
        hash_value = 0;
        int resi = n;
        for (int j = n-1; j>0; j--) {
            hash_value = (hash_value + (s.charAt(j) - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
            if(prefix.contains(hash_value)) resi = j;
        }
        return s.substring(resi, n);
    }
}