import java.util.ArrayList;
import java.util.List;

class Solution {
    List<TreeNode>[] dp = new List[20];
    public List<TreeNode> allPossibleFBT(int n) {
        List<TreeNode> res = new ArrayList<>();
        if(n%2==0) return res;
        if(dp[n]!=null) return dp[n];
        TreeNode root;
        if(n==1) {
            res.add( new TreeNode(0));
            return res;
        }
        n--;
        for(int i=1;i<n;i++){
            List<TreeNode> left = allPossibleFBT(i);
            List<TreeNode> right = allPossibleFBT(n-i);
            root = new TreeNode(0);
            for(TreeNode l:left){
                root.left = l;
                for(TreeNode r:right){
                    root.right = r;
                    res.add(root);
                }
            }
            
        }
        dp[n+1] = res;
        return res;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.allPossibleFBT(7));
    }
}