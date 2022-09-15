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
    int min=3001;
    int max =0;
    void solve(TreeNode root,int idx){
        if(root==null) return;
        root.val = idx;
        if(root.left!=null) solve(root.left,2*idx+1);
        if(root.right!=null) solve(root.right,2*idx+2);
    }
    class Pair{
        TreeNode node;
        int h;
        Pair(TreeNode node,int h){
            this.node = node;
            this.h = h;
        }
    }
    public int widthOfBinaryTree(TreeNode root) {
        solve(root,0);
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root,1));
        HashMap<Integer,Integer> mins = new HashMap<>();
        HashMap<Integer,Integer> maxs = new HashMap<>();
        Pair p = q.peek();
        while(!q.isEmpty()){
            p = q.remove();
            if(!mins.containsKey(p.h)){
                mins.put(p.h,p.node.val);
            }
            else{
                mins.put(p.h,Math.min(p.node.val,mins.get(p.h)));
            }
            if(!maxs.containsKey(p.h)){
                maxs.put(p.h,p.node.val);
            }
            else{
                maxs.put(p.h,Math.max(p.node.val,maxs.get(p.h)));
            }
            if(p.node.left!=null) q.add(new Pair(p.node.left,p.h+1));
            if(p.node.right!=null) q.add(new Pair(p.node.right,p.h+1));
        }
        int diff=0;
        for(int i=1;i<=p.h;i++){
            diff = Math.max(maxs.get(i)-mins.get(i)+1,diff);
        }
        return diff;
    }
}