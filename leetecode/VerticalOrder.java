import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;;
class Solution {
    class SNOde{
        int x;
        int y;
        TreeNode node;
        public String toString(){
            return " x = " + x + " val " + node.val + " h " + y;
        }
        SNOde(int x,int y,TreeNode node){
            this.x = x;
            this.y=y;
            this.node = node;
        }

    }
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        Queue<SNOde> q = new LinkedBlockingQueue<>();
        HashMap<Integer,List<SNOde>> map = new HashMap<>();
        q.offer(new SNOde(0,0,root));
        
        while (!q.isEmpty()) {
            int sz = q.size();
            for (int i=0;i<sz;i++) {
                SNOde snode = q.poll();
                if(!map.containsKey(snode.x)) map.put(snode.x,new ArrayList<>());
                map.get(snode.x).add(snode);
                if(snode.node.left!=null) q.add(new SNOde(snode.x-1, snode.y+1, snode.node.left));
                if(snode.node.right!=null) q.add(new SNOde(snode.x+1, snode.y+1, snode.node.right));
            }
        }
        List<List<Integer>> res = new ArrayList<>();
        int from = Collections.min(map.keySet());
        int to = Collections.max(map.keySet());
        for (int i = from; i <=to; i++) {
            if(!map.containsKey(i)) continue;
            List<Integer>  ab= new ArrayList<>();
            Collections.sort(map.get(i),(a,b)-> a.y==b.y ? a.node.val-b.node.val : a.y-b.y);
            for (SNOde sn : map.get(i)) {
                ab.add(sn.node.val);
            }
            res.add(ab);
        }
        return res;

    }
}