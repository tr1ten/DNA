import java.util.HashMap;
import java.util.*;
class Solution {
    public String oddString(String[] words) {
        HashMap<HashSet<Integer>,Integer> map = new HashMap<>(); 
        HashMap<HashSet<Integer>,String> map2 = new HashMap<>();
        for (String word : words) {
            HashSet<Integer> set = new HashSet();
            for (int i = 1; i < word.length(); i++) {
                set.add(word.charAt(i)-word.charAt(i-1));
            }
            map2.put(set,s);
            map.put(set,map.getOrDefault(set,0)+1);
        }
        int m = Collections.max(map.valueSet());
        for (HashSet<Integer> s:map.keySet()) {
            if(map.get(s)<m) return map2.get(s);
        }
        public boolean solve(String text1, String text2) {
            int c = 0;
            for (int i = 0; i < text1.length(); i++) {
                if(text1.charAt(i)!=text2.charAt(i)) c++;
                if(c>2) return false;
            }
            return c<=2;
        }
        public List<String> twoEditWords(String[] queries, String[] dictionary) {
            int n = queries[0].length();
            List<Integer> res = new ArrayList<>();
            for (String q : queries) {
                for (String d : dictionary) {
                    if(solve(q,d)){
                        res.add(q);
                        break;
                    }
                }
            }
            return res;
        }
    }
}