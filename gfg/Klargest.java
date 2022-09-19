class Solution
{
    int k;
    int klarge;
    void solve(Node root){
        if(root==null) return;
        if(root.right!=null) return solve(root.right);
        if(k==1) klarge = root.data;
        k--;
        
    }
    // return the Kth largest element in the given BST rooted at 'root'
    public int kthLargest(Node root,int K)
    {
        this.k = K;
        solve(root);'
        return klarge;
    }
}