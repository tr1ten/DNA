package leetecode;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
public class NextRightPointer {
    public Node connect(Node root) {
        if(root==null) return  null;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        int lvl  =0;
        double nodes = Math.pow(2,lvl);
        Node node;
        while (!queue.isEmpty()){
            node = queue.remove();
            nodes--;
            if(node.left!=null) queue.add(node.left);
            if(node.right!=null) queue.add(node.right);
            if(nodes==0){
                node.next = null;
                lvl++;
                nodes = Math.pow(2,lvl);
            }
            else{
                node.next = queue.peek();
            }
        }
        return root;
    }
}
