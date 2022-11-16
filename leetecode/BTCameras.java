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

// without memoization TLE
class Solution {
    
    int solve(TreeNode root,boolean cam,boolean mcam){
        if(root==null) return mcam ? 1001 : 0;
        int res = solve(root.left,true,false) + solve(root.right,true,false) + 1;
        if(mcam) return res;
        res = Math.min(solve(root.left,false,!cam)+solve(root.right,false,false),res);
        if(!cam) res = Math.min(solve(root.right,false,!cam)+solve(root.left,false,false),res);
        return res;
        
    }
    public int minCameraCover(TreeNode root) {
        if(root.left==null && root.right==null) return 1;
        return Math.min(solve(root,false,true),solve(root,false,false));
    }
}



