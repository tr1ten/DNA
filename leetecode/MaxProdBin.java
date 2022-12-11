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
    long res;
    long total;
    static int MOD = 10_000_000_07;
    private long sum(TreeNode root){
        if(root==null) return 0;
        return (root.val + sum(root.left) + sum(root.right));
    }
    private long solve(TreeNode root){
        if(root==null) return 0;
        long left = solve(root.left);
        res = Math.max(res,(((total-left))*(left))%MOD);
        long right = solve(root.right);
        res = Math.max(res,(((total-right))*(right))%MOD);
        return left+right+root.val;
        
    }
    public int maxProduct(TreeNode root) {
        res = 0;
        total = sum(root);
        solve(root);
        return (int)(res%MOD);
    }
}