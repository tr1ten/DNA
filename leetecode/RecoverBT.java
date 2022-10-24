class Solution {
    TreeNode first;
    TreeNode last;
    TreeNode ln;
    void inorder(TreeNode node){
        if(node==null) return;
        inorder(node.left);
        if(ln!=null && ln.val>=node.val){
            if(first!=null) last = node;
            else {
                first= ln;
            }
        }
        ln = node;
        inorder(node.right);
    }
    void swap(TreeNode t1,TreeNode t2){
        int temp  =t1.val;
        t1.val = t2.val;
        t2.val = temp;
    }
    public void recoverTree(TreeNode root) {
            inorder(root);
             swap(first, last);
    }
}