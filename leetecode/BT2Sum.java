import java.util.Stack;

class Solution {
    public boolean findTarget(TreeNode root, int k) {
        Stack<TreeNode> left_st = new Stack<>();
        Stack<TreeNode> right_st = new Stack<>();
        TreeNode node = root;
        while (node!=null) {
            left_st.push(node);
            node = node.left;
        }
        node = root;
        while (node!=null) {
            right_st.push(node);
            node = node.right;
        }
        while (left_st.peek()!=right_st.peek()) {
            int s = left_st.peek().val + right_st.peek().val;
            if(s==k) return true;
            if(s<k){
                // find next greator element
                node = left_st.pop().right;
                while (node!=null) {
                    left_st.push(node);
                    node = node.left;
                }
            }
            else{
                // find next lower element
                node = right_st.pop().left;
                while (node!=null) {
                    right_st.push(node);
                    node = node.right;
                }
            }
        }
        return false;
    }
}