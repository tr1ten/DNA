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
    class Tnode{
        TreeNode node;
        int l;
        Tnode(TreeNode node,int l){
            this.node = node;
            this.l = l;
        }
    }
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        if(root==null) return res;
        Queue<Tnode> q = new LinkedList<>();
        q.add(new Tnode(root,0));
        while(!q.isEmpty()){
            Tnode tn = q.remove();
            if(tn.l>=res.size()){
                List<Integer> ls = new ArrayList<>();
                ls.add(tn.node.val);
                res.add(ls);
            }
            else{
                res.get(tn.l).add(tn.node.val);
            }
            if(tn.node.left!=null) q.add(new Tnode(tn.node.left,tn.l+1));
            if(tn.node.right!=null) q.add(new Tnode(tn.node.right,tn.l+1));

        }
        for(int i=0;i<res.size();i++){
            if((i&1)!=0){
                Collections.reverse(res.get(i));
            }
        }
        return res;
    }
}