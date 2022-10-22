
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;

import DS.TreeNode;

class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        Queue<TreeNode> q = new LinkedBlockingQueue<>();
        q.offer(root);
        while(!q.isEmpty()){
            int sz = q.size();
            HashMap<Integer,Integer> hm = new HashMap<>();
            while(sz-->0){
                TreeNode rt = q.poll();
                if(rt.left!=null) {
                    q.offer(rt.left);
                    if(rt.left.val==x && hm.containsKey(y)) return  hm.get(y)!=rt.val; 
                    if(rt.left.val==y && hm.containsKey(x)) return  hm.get(x)!=rt.val; 
                    hm.put(rt.left.val, rt.val);
                }
                if(rt.right!=null) {
                    q.offer(rt.right);
                    if(rt.right.val==x && hm.containsKey(y)) return  hm.get(y)!=rt.val; 
                    if(rt.right.val==y && hm.containsKey(x)) return  hm.get(x)!=rt.val; 
                    hm.put(rt.right.val, rt.val);
                }
            }
        }
        return false;
    }
}