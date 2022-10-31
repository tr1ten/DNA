import java.util.HashMap;
import java.util.AbstractMap.SimpleEntry;
import java.util.*;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    HashMap<SimpleEntry<TreeNode,Boolean>,Integer> dp;
    int solve(TreeNode node,boolean canPick){
        if(node==null) return 0;
        SimpleEntry<TreeNode,Boolean> key = new SimpleEntry<>(node,canPick);
        if(dp.containsKey(key)) return dp.get(key);
        int np = solve(node.left,true) +solve(node.right,true);
        if(canPick){
            np = Math.max(np,node.val+ solve(node.left,false) +solve(node.right,false));
        }
        dp.put(key,np);
        return np;
    }
    public int rob(TreeNode root) {
        dp = new HashMap<>();
        return solve(root,true);
    }
}