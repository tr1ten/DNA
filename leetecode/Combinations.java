import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    Set<Set<Integer>> allSets = new HashSet<>();
    void solve(int n, int k,Set<Integer> set, int start){
        if(k==0) {
            allSets.add(new HashSet<>(set));
            return;
        }
        for (int i = start; i <=n; i++) {
            if(set.contains(i)) continue;
            set.add(i);
            solve(n, k-1, set,i+1);
            set.remove(i);
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        solve(n, k, new HashSet<>(),1);
        for (Set<Integer> set : allSets) {
            res.add(new ArrayList<>(set));
        }
        return res;

    }
}
;

class Solution2 {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> p = Arrays.asList(new Integer[k]);
        Collections.fill(p, 0);
        int i=0;
        while(i>=0){
            p.set(i,p.get(i)+1);
            if(p.get(i)>n) --i;
            else if(i==k-1) res.add(new ArrayList(p));
            else{
                i++;
                p.set(i,p.get(i-1));
            }
        }
        return res;

    }
}