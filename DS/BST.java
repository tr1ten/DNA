package DS;


class TreeNode {
    TreeNode right;
    TreeNode left;
    int val;
    TreeNode(int val) {this.val = val;}
    TreeNode(int val,TreeNode r,TreeNode l) {
        this.val = val;
        this.right = r;
        left = l;
    }

}
public class BST {
    TreeNode root;
    TreeNode _insert(TreeNode root,int val){
        if(root==null) return new TreeNode(val);
        if(root.val<val) root.right = _insert(root.right, val);
        else root.left = _insert(root.left, val);
        return root;
    }
    // insert
    void insert(int val){
        root = _insert(root, val);
    }
    
    TreeNode _delete(TreeNode root,int val){
        if(root==null) return root;
        if(root.val==val){
            // if either is null return other
            if(root.left==null) return root.right;
            if(root.right==null) return root.left;
            TreeNode temp = root.right;
            TreeNode p = null;
            // find min in right subtree
            while(temp.left!=null){
                p =temp;
                temp =temp.left;
            }
            // swap and return root
            if(p!=null) p.left = null;
            temp.left = root.left;
            temp.right = root.right;
            return temp;
        }
        else if(root.val<val) root.right = _delete(root.right, val);
        else root.left = _delete(root.left, val);
        return root;
    }
    
    // delete
    void delete(int val){
        root = _delete(root, val);
    }

    void inorder(TreeNode root){
        if(root==null) return;
        inorder(root.left);
        System.out.print(root.val + " ,");
        inorder(root.right);
    }
    void print() {
        System.out.println("\nTree ->");
        inorder(root);
    }
    public static void main(String[] args) {
        BST bs = new BST();
        bs.insert(10);
        bs.insert(20);
        bs.insert(25);
        bs.insert(5);
        bs.insert(15);
        bs.insert(8);
        bs.insert(9);
        bs.insert(6);
        bs.insert(4);
        bs.print();;
        bs.delete(4);
        bs.delete(5);
        bs.print();;

    }
}
