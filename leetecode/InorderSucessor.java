import java.util.Stack;

public class TreeNode {
         int val;
         TreeNode left;
         TreeNode right;
         TreeNode(int x) { val = x; }
 }
class Solution {
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    
    
    TreeNode min(TreeNode root){
        if(root.left!=null) return min(root.left);
        return root;
    }
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if(root==null) return null;
        if(p.right!=null) return min(p.right);
        Stack<TreeNode> st = new Stack<>();
        while (root!=null) {
            if(root==p) break;
            st.add(root);
            if(root.val<p.val) root = root.right;
            else root = root.left; 
        }
        TreeNode x = p;
        while(!st.isEmpty() && st.peek().left!=x){
            x = st.pop();
        }
        return st.isEmpty() ? null : st.peek();

    }
}