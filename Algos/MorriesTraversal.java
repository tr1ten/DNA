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
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> ls = new ArrayList<>();
        TreeNode cur = root;
        while(cur!=null){
            if(cur.left==null){
                ls.add(cur.val);
                cur = cur.right;
            }
            else{
            TreeNode left = cur.left;
                while(left.right!=null && left.right!=cur){
                    left = left.right;
                }
                if(left.right==null){
                    left.right = cur;
                    cur = cur.left;
                }
                else{
                    left.right = null;
                    ls.add(cur.val);
                    cur = cur.right;
                }
            }
        }
        return ls;
    }
}