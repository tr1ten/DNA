import java.util.* ;
import java.io.*; 
/************************************************************

    Following is the TreeNode class structure

    class TreeNode<T>
    {
       public:
        T data;
        TreeNode<T> left;
        TreeNode<T> right;

        TreeNode(T data)
        {
            this.data = data;
            left = null;
            right = null;
        }
    };

************************************************************/

public class Solution {

    public static int floorInBST(TreeNode<Integer> root, int X) {
        if(root==null) return Integer.MAX_VALUE;
        if(root.data==X) return root.data;
        int c=0;
        if(root.data>X) c=floorInBST(root.left,X);
        else c=floorInBST(root.right,X);
        if(c>X) return root.data;
        return c;
    }
}