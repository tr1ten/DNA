class Solution {
    int sum=0;
    void solve(TreeNode root, String sb){
        if(root==null) return;
        String s =sb + root.val;
        boolean flag = false;
        if(root.right!=null){
            solve(root.right, s);
            flag = true;
        }
        if(root.left!=null){
            solve(root.left, s);
            flag = true;
        }
        if(!flag){
            int a=0;
            for (int i = 0; i < sb.length(); i++) {
                a += (sb.charAt(i)-'0')<<(sb.length()-1-i);
            }
            sum +=a;
            return;
        }


    }
    public int sumRootToLeaf(TreeNode root) {
        solve(root, "");
        return sum;
    }
}