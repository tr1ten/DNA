
import java.util.HashMap;

// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node temp = head;
        Node nhead = new Node(0);
        Node temp2 = nhead;
        HashMap<Node,Node> hm = new HashMap<>(); 
        while (temp!=null) {
            temp2.next = new Node(temp.val);
            hm.put(temp, temp2.next);
            temp = temp.next;
            temp2 = temp2.next;
        }
        temp = head;
        temp2 = nhead.next;
        while (temp!=null) {
            temp2.random = temp.random==null ? null : hm.get(temp.random);
            temp = temp.next;
            temp2 = temp2.next;
        }
        return nhead.next;
    }
}