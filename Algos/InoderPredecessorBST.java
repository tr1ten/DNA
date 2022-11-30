package Algos;
import java.util.Stack;

import TreeNode;

class TreeNode {
         int val;
         TreeNode left;
         TreeNode right;
         TreeNode(int x) { val = x; }
 }
class Solution {
    TreeNode max(TreeNode root){
        if(root.right!=null) return max(root.right);
        return root;
    }
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    // public TreeNode inorderPredecessor(TreeNode root, TreeNode p) {
    //     if(root==null) return null;
    //     if(p.left!=null) return max(p.left);
    //     Stack<TreeNode> st = new Stack<>();
    //     while (root!=null) {
    //         if(root==p) break;
    //         st.add(root);
    //         if(root.val<p.val) root = root.right;
    //         else root = root.left; 
    //     }
    //     TreeNode x = p;
    //     while(!st.isEmpty() && st.peek().right!=x){
    //         x = st.pop();
    //     }
    //     return st.isEmpty() ? null : st.peek();

    // }
    TreeNode pre = null;
    void rec(TreeNode root,TreeNode p){
        if(root==null) return;
        if(root.val<p.val){
            pre = root;
            rec(root.right, p);
        }
        else{
            rec(root.left,p);
        }
    }
    /**
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    public TreeNode inorderPredecessor(TreeNode root, TreeNode p) {
        pre = null;
        rec(root, p);
        return pre;
    }
}