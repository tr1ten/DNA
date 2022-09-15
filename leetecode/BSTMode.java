import java.util.Queue;

class Solution {
    HashMap<Integer,Integer> hm;
    void inorder(TreeNode root){
        if(root==null) return;
        inorder(root.left);
        if(hm.containsKey(root.val)) hm.put(root.val,hm.get(root.val)+1);
        else hm.put(root.val,1);
        inorder(root.right);
        
    }
    public int[] findMode(TreeNode root) {
        hm = new HashMap<>();
        inorder(root);
        PriorityQueue<int[]> pq = new PriorityQueue((a,b)->b[1]-a[1]);
        for(var et:hm.entrySet()){
            pq.offer(new int[]{et.getKey(),et.getValue()});
        }
        int max = pq.peek()[1];
        ArrayList<Integer> al = new ArrayList<>();
        while(!pq.isEmpty() && pq.peek()[1]==max){
            al.add(pq.poll()[0]);
        }
        int[] ans = new int[al.size()];
        for(int i=0;i<al.size();i++) ans[i] = al.get(i);
        return ans;                                     
    }
}