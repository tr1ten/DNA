/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
public class Solution {
    class TN{
        TreeNode cur;
        TN prev;
        TN(TreeNode v,TN p){
            cur = v;
            prev = p;
        }
    }
    public ArrayList<Integer> solve(TreeNode A, int B) {
        Queue<TN> q = new LinkedList<>();
        q.add(new TN(A,null));
        TN ft=null;
        while(!q.isEmpty()){
            TN tn = q.remove();
            if(tn.cur.val==B){
                ft = tn;
                break;
            }
            if(tn.cur.left!=null) q.add(new TN(tn.cur.left,tn));
            if(tn.cur.right!=null) q.add(new TN(tn.cur.right,tn));
        }
        Stack<Integer> st = new Stack<>();
        while(ft!=null){
            st.push(ft.cur.val);
            ft = ft.prev;
        }
        ArrayList<Integer> ar = new ArrayList<>();
        while(!st.isEmpty()) ar.add(st.pop());
        return ar;
    }
}
