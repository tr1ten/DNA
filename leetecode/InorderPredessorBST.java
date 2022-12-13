/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */

public class Solution {
    TreeNode max(TreeNode root){
        if(root.right!=null) return max(root.right);
        return root;
    }
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    public TreeNode inorderPredecessor(TreeNode root, TreeNode p) {
        if(root==null) return null;
        if(p.left!=null) return max(p.left);
        Stack<TreeNode> st = new Stack<>();
        while(root!=p){
            st.push(root);
            if(root.val>p.val) root = root.left;
            else root=root.right;
        }
        TreeNode x = p;
        while(!st.isEmpty() && st.peek().right!=x){
            x=st.pop();
        }
        return st.isEmpty() ? null : st.pop();
    }
}