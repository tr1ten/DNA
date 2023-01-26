import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
    class TreeNode<T> {
        T data;
        ArrayList<TreeNode<T>> children;

        public TreeNode(T data) {
            this.data = data;
            this.children = new ArrayList<>();
        }

        public int numChildren() {
            return this.children.size();
        }

        public TreeNode<T> getChild(int index) {
            if (index > this.children.size()) {
                return null;
            }

            return this.children.get(index);
        }
    }



public class Solution {

    static int dfs(TreeNode<Integer> node,Set<Integer> s){
        if(node == null) return 0;
        int res = 0;
        if(s.contains(node.data)) return 0;
        res+=1;
        s.add(node.data);
        int n = node.numChildren();
        for(int i=0;i<n;i++){
            res+=dfs(node.getChild(i),s);
        }
        s.remove(node.data);
        return res;
    }
    public static int countSpecialNodes(TreeNode<Integer> root) {
        return dfs(root, new HashSet<>());

    }
}