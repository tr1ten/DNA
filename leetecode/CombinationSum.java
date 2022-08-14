

import java.util.ArrayList;
import java.util.List;

public class CombinationSum {
    List<List<Integer>> allRes;
    private void rec(int[] candidates,int target,int cur,ArrayList<Integer> path,int start){
        if(cur>target) return;
        if(cur==target){
            allRes.add((List<Integer>) path.clone());
            return;
        }
        if(path==null) path = new ArrayList<>();
        for(int i=start;i<candidates.length;i++) {
            path.add(candidates[i]);
            rec(candidates,target,cur+candidates[i],path, i+1);
            path.remove(path.size()-1);
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        allRes = new ArrayList<>();
        rec(candidates,target,0,null,0);
        return allRes;
    }
}
