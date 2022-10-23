import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;
import java.util.*;;

class Solution {
    public String frequencySort(String s) {
        StringBuilder sb = new StringBuilder();
        HashMap<Character,Integer> hm = new HashMap<>();
        for(Character c:s.toCharArray()) hm.put(c,hm.getOrDefault(c,0)+1);
        PriorityQueue<Map.Entry<Character,Integer>> pq = new PriorityQueue<>((a,b)->b.getValue()-a.getValue());
        pq.addAll(hm.entrySet());
        while(!pq.isEmpty()){
            Map.Entry<Character,Integer> e = pq.poll();
            for(int i=0;i<e.getValue();i++) sb.append(e.getKey());
        }
        return sb.toString();
    }
}