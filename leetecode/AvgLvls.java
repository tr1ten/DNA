

import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;

import DS.TreeNode;

class Solution {
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> q = new LinkedBlockingQueue<>();
        q.offer(root);
        ArrayList<Double> res = new ArrayList<>();
        res.add(root.val*1.0);
        while(!q.isEmpty()){
            int sz = q.size();
            int sum =0;
            int k=0;
            while(sz-->0){
                TreeNode rt = q.poll();
                if(rt.left!=null) {
                    q.offer(rt.left);
                    sum+= rt.left.val;
                    k++;
                }
                if(rt.right!=null) {
                    q.offer(rt.right);
                    sum+=rt.right.val;
                    k++;
                }
            }
            if(k>0) res.add(sum*1.0/k);
        }
        return res;
    }
}
