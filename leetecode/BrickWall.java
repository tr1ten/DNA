import java.util.HashMap;
import java.util.List;
class Solution {
    public int leastBricks(List<List<Integer>> wall) {
        int max = 0;
        int n = wall.size();
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i=0;i<n;i++){
            int m = wall.get(i).size();
            if(m==1) continue; // dont add last edge 
            Integer[] rg = new Integer[m-1];
            rg[0] = wall.get(i).get(0);
            for(int j=1;j<m-1;j++){
                rg[j] = rg[j-1] + wall.get(i).get(j);
            }
            for (int sm:rg) {
                hm.put(sm, hm.getOrDefault(sm, 0)+1);
            }
        }
        System.out.println(hm);
        for (int k:hm.keySet()) {
            max = Math.max(max, hm.get(k));
        }
        return n-max;
    }
}