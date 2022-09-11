class Solution {
        HashMap<int[], List<List<Integer>>> map = new HashMap<int[], List<List<Integer>>>();
        List<List<Integer>> solve(int[] candidates,int target,int idx,int sum){
        int[] key = new int[]{idx,sum};
        // if(map.containsKey(key)){
        //     return map.get(key);
        // }
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if(idx>=candidates.length){
            if(sum==target) {
                    res.add(new ArrayList<Integer>());
                    return res;
            }
            return null;
        }
        
        if(sum+candidates[idx]<=target){
            List<List<Integer>> temp = solve(candidates,target,idx+1,sum+candidates[idx]);
            if(temp!=null){
                for(List<Integer> l:temp){
                    l.add(candidates[idx]);
                    res.add(l);
                }
            }
        }
        while(idx+1<candidates.length && candidates[idx]==candidates[idx+1]){
            idx++;
        }
        List<List<Integer>> t = solve(candidates,target,idx+1,sum);
        if(t!=null) res.addAll(t);
        map.put(key,res);
        return res;
        
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target){
        Arrays.sort(candidates);
        return solve(candidates,target,0,0);
    }
}

// better sol
class Solution2 {
        public List<List<Integer>> combinationSum2(int[] cand, int target) {
    Arrays.sort(cand);
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    List<Integer> path = new ArrayList<Integer>();
    dfs_com(cand, 0, target, path, res);
    return res;
}
void dfs_com(int[] cand, int cur, int target, List<Integer> path, List<List<Integer>> res) {
    if (target == 0) {
        res.add(new ArrayList(path));
        return ;
    }
    if (target < 0) return;
    for (int i = cur; i < cand.length; i++){
        if (i > cur && cand[i] == cand[i-1]) continue;
        path.add(path.size(), cand[i]);
        dfs_com(cand, i+1, target - cand[i], path, res);
        path.remove(path.size()-1);
    }
}
}