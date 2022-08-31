import java.util.*;
class Solution {
    List<List<Integer>> sols;
    private void rec(LinkedHashSet<Integer> path,int[] nums){
        if(path.size()==nums.length) {
            var ls = new ArrayList<Integer>();
            for (var x : path) {
                ls.add(x);
            }
            sols.add(ls);
            return;
        }
        for (int x : nums) {
            if(!path.contains(x)) {
                path.add(x);
                rec(path, nums);
                path.remove(x);
            }
        }

    }
    public List<List<Integer>> permute(int[] nums) {
        sols = new ArrayList<>();
        rec(new LinkedHashSet<Integer>(), nums);
        return sols;
    }
    public static void main(String[] args) {
        var solver = new Solution();
        solver.permute((new int[]{1,2,3}));
    }
} 