import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.AbstractMap.SimpleEntry;

public class WC317 {
    public int averageValue(int[] nums) {
        int sum =0;
        int cnt = 0;
        for (int x : nums) {
            if(x%6==0){
                sum += x;
                cnt++;
            }
        }
        return cnt==0?0 : sum/cnt;
    }
    public List<List<String>> mostPopularCreator(String[] creators, String[] ids, int[] views) {
        int n = creators.length;
        HashMap<String,Integer> pop = new HashMap<>();
        HashMap<String,SimpleEntry<String,Integer>> mostView = new HashMap<>();
        List<List<String>> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pop.put(creators[i], pop.getOrDefault(creators[i], 0)+views[i]);
            if(!mostView.containsKey(creators[i]) || mostView.get(creators[i]).getValue()<views[i] || (mostView.get(creators[i]).getValue()==views[i] && mostView.get(creators[i]).getKey().compareTo(ids[i])>0) ){
                mostView.put(creators[i], new SimpleEntry<>(ids[i],views[i]));
            }
        }
        int mx = Collections.max(pop.values());
        for (String key : pop.keySet()) {
            if(pop.get(key)==mx){
                List<String> ls = new ArrayList<>();
                ls.add(key);
                ls.add(mostView.get(key).getKey());
                res.add(ls);
            }
        }
        return res;
 
    }
    Integer[] dp;
    int ht(TreeNode node,int end){
        if(node==null || node.val==end) return 0;
        return 1+Math.max(ht(node.left, end),ht(node.right, end));
    }
    public int[] treeQueries(TreeNode root, int[] queries) {
        int[] res = new int[queries.length];
        dp = new Integer[100001];
        for (int i = 0; i < res.length; i++) {
            res[i] = ht(root, queries[i]);
        }
        return res;
    }

}
