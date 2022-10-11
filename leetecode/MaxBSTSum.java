
class Solution {
    class Per{
        public int maxSum;
        public int min;
        public int max;
        Per(int x,int y,int z) {
            this.maxSum = x;
            this.min = y;
            max = z;
        }
    }
    int maxVal=0;
    int min3(int a,int b,int c) {
        return Math.min(a,Math.min(b,c));
    }
    int max3(int a,int b,int c) {
        return Math.max(a,Math.max(b,c));
    }
    Per solve(TreeNode root){
        if(root==null) return new Per(0,Integer.MAX_VALUE,Integer.MIN_VALUE);
        if(root.left==null && root.right==null) return new Per(root.val,root.val,root.val);
        Per left = solve(root.left);
        Per right = solve(root.right);
        if(left.max<root.val && right.min>root.val) {
            int ts = root.val+left.maxSum+right.maxSum;
            int mx = Math.max(left.maxSum, right.maxSum);
            this.maxVal = max3(this.maxVal, ts,mx);
            if(mx>ts) return new Per(mx,Integer.MIN_VALUE,Integer.MAX_VALUE);
            return new Per(ts,min3(left.min,right.min,root.val),max3(left.max,right.max,root.val));
        }
        return new Per(Math.max(left.maxSum, right.maxSum),Integer.MIN_VALUE,Integer.MAX_VALUE);

    }
    public int maxSumBST(TreeNode root) {
        solve(root);
        return this.maxVal;
        
    }
}