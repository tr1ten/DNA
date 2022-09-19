import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    boolean visited;
    TreeNode(int x) { val = x; }
}
class Codec {

    int[] po;
    TreeNode helper(int i,int j){
        if(j<i) return null;
        if(i==j) return new TreeNode(po[i]);
        int k=i+1;
        while(k<po.length && po[k]<po[i]) k++;
        TreeNode node = new TreeNode(po[i]);
        node.left = helper(i+1,k-1);
        node.right = helper(k,j);
        return node;
    }
    public TreeNode bstFromPreorder(int[] preorder) {
        this.po = preorder;
        return helper(0,preorder.length-1);
    }
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ls = new ArrayList<>();
        if(root==null) return ls;
        Stack<TreeNode> st = new Stack<>();
        st.push(root);
        while(!st.empty()){
            TreeNode node = st.pop();
            ls.add(node.val);
            if(node.right!=null) st.push(node.right);
            if(node.left!=null) st.push(node.left);
        }                                                                                                                                                                                                                                                                                                                 
        return ls;
    }
    
    
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        List<Integer> ls = preorderTraversal(root);
        StringBuilder sb =new StringBuilder();
        for (int i = 0; i < ls.size(); i++) {
            sb.append(ls.get(i)+ ",");
        }
        sb.append(ls.get(ls.size()-1) + "");
        return sb.toString();
    }
    
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] strs = data.split(",");
        int[] preorder = new int[strs.length];
        int i =0;
        for (String s : strs) {
            preorder[i++] = Integer.parseInt(s);
        }
        return bstFromPreorder(preorder);
    }
    // store each level value inside a list 
}

// Your Codec object will be in   tantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// String tree = ser.serialize(root);
// TreeNode ans = deser.deserialize(tree);
// return ans;