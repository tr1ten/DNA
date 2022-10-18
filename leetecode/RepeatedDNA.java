import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<String> map = new HashSet<>();
        List<String> ls = new ArrayList<>();
        if(s.length()<10) return ls;
        int p2=9;
        StringBuilder sb= new StringBuilder(s.substring(0,9));
        int len = s.length();
        while (p2<len) {
                sb.append(s.charAt(p2));
                String str = sb.toString();
                if(map.contains(str)) ls.add(str);
                else map.add(str);
                sb.deleteCharAt(0);
                p2++;
            
        }
        return ls;
    }
}