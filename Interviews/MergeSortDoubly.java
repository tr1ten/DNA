package Interviews;

public class MergeSortDoubly {
    static class Node {
        Node prev;
        Node next;
        int val;
        
    }
    Node merge(Node root1,Node ul,Node root2,Node ur){
        if(root1==null) return root2;
        if(root2==null) return root1;
        
        Node dhead = new Node();
        Node pt = dhead;
        while (root1!=ul && root2!=ur) {
            if(root1.val<root2.val) {
                pt.next = root1;
                root1 = root1.next;
            }
            else{
                pt.next = root2;
                root2 = root2.next;
            }
            pt = pt.next;
        }
        while(root1!=null) {
            pt.next = root1;
            pt = pt.next;
            root1 = root1.next;
        }
        while(root2!=null) {
            pt.next = root2;
            pt = pt.next;
            root2 = root2.next;
        }
        // pt.next = null;
        pt.next = ur;
        return dhead.next;
    }
    Node mergeSort(Node root,Node up){
        if(root==up || root.next==up) return root;
        Node slow = root;
        Node fast = root;
        while (fast!=up && fast.next!=up) {
            fast = fast.next.next;
            slow = slow.next;
        }
        Node left = mergeSort(root, slow);
        Node right = mergeSort(slow, up);
        return merge(left, slow, right, up);
    }
    // test
    public static void main(String[] args) {
        MergeSortDoubly obj = new MergeSortDoubly();
        Node root = new Node();
        root.val = 10;
        root.next = new Node();
        root.next.val = 4;
        // root.next.next = new Node();
        // root.next.next.val = 3;
        // root.next.next.next = new Node();
        // root.next.next.next.val = 4;
        // root.next.next.next.next = new Node();
        // root.next.next.next.next.val = 20;
        Node pt = obj.mergeSort(root, null);
        while (pt!=null) {
            System.out.println(pt.val);
            pt = pt.next;
        }
    }
}
