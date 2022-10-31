import java.util.Arrays;
import java.util.HashMap;

class Solution {
    int[] depth; // at which depth node is located
    HashMap<Integer,int[][]> map; // max two height at each depth
    // max in binary tree
    int max(TreeNode node){
        if(node==null) return 0;
        return Math.max(node.val, Math.max(max(node.left), max(node.right)));
    }
    int compute(TreeNode node,int h){
        if(node==null) return h-1;
        depth[node.val] = h;
        int[][] value;
        if(!map.containsKey(h)){
            value =  new int[2][2];
            map.put(h,value);
        }
        else{
            value = map.get(h);
        }
        int max = Math.max(compute(node.left, h+1), compute(node.right, h+1));
        if(value[0][0]<max){
            value[1][0] = value[0][0];
            value[1][1] = value[0][1];
            value[0][0] = max;
            value[0][1] = node.val;
        }        
        else if(value[1][0]<max){
            value[1][0] = max;
            value[1][1] = node.val;
        }
        return max;
    }
    public int[] treeQueries(TreeNode root, int[] queries) {
        int[] res = new int[queries.length];
        int n = max(root);
        depth = new int[n+1];
        map = new HashMap<>();
        compute(root, 0);
        // print map
        for (int key : map.keySet()) {
            System.out.println(key+" "+Arrays.deepToString(map.get(key)));
        }

        for (int i = 0; i < res.length; i++) {
            int q = queries[i];
            int d = depth[q];
            int[][] value = map.get(d);
            if(value[0][1]==q){
                if(value[1][0]==0) res[i] = d-1;
                else res[i] = value[1][0];
            }
            else {
                res[i] = value[0][0];
            }
        }
        return res;
    }
}