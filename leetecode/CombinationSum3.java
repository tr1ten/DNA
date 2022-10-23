import java.util.*;
import java.util.HashSet;
class Solution {
    Set<Set<Integer>> combs;
    void solve(int k,int n,boolean[] visited){
        if(n==0 && k==0){
            Set<Integer> set = new HashSet<>();
            for (int i = 1; i <=9; i++) {
                if(visited[i]) set.add(i);
            }
            combs.add(set);
        }
        if(n==0 || k==0) return;
        for (int i = 1; i <=Math.min(9, n); i++) {
            if(!visited[i]){
                visited[i] = true;
                solve(k-1, n-i, visited);
                visited[i] = false;
            }
        }

    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        combs = new HashSet<>();
        solve(k, n, new boolean[10]);
        List<List<Integer>> ans = new ArrayList<>();
        for (Set<Integer> comb : combs) {
            List<Integer> list = new ArrayList<>(comb);
            Collections.sort(list);
            ans.add(list);
        }
        return ans;
    }
}