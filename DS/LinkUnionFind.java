package DS;

import java.util.HashMap;

/**
 * Very Basic Immplementation of Union Find
 * UnionFind
 */


/**
 * TestUnionFind
 */
class TestUnionFind {
    public static void main(String[] args) {
        UnionFind uf = new LinkUnionFind(10);
        uf.union(1, 0);
        uf.union(0, 2);
        uf.union(2, 3);
        // uf.union(1, );
        System.out.println(uf.find(1)==uf.find(3));
    }
    
}

interface UnionFind {
    void createSet(int x);
    void union(int x,int y);
    LinkedList find(int x);

}
public class LinkUnionFind implements UnionFind{
    HashMap<Integer,LinkedList> rootLL;
    public LinkUnionFind(int N){
        rootLL = new HashMap<>();
        for (int i = 0; i < N; i++) {
            createSet(i);
        }
    }
    @Override
    public void createSet(int x) {
        assert find(x)==null;
        LinkedList ll = new LinkedList();
        ll.head = new LNode(x);
        ll.tail = ll.head;
        rootLL.put(x, ll);
    }
    @Override
    public LinkedList find(int x) {
        return rootLL.getOrDefault(x, null);
    }
    @Override
    public void union(int x, int y) {
        LinkedList set1 = find(x);
        LinkedList set2 = find(y);
        assert set1!=null && set2!=null && set1!=set2;
        set1.tail.next = set2.head;
        set1.tail = set2.tail;
        LNode temp = set2.head;
        while(temp!=null){
            rootLL.put(temp.data, set1);
            temp = temp.next;
        }
    }
}

class LNode{
    int data;
    LNode next;
    LNode(int data){
        this.data = data;
        next = null;
    }

    
}
class LinkedList{
    LNode head;
    LNode tail;
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        LNode temp = head;
        while(temp!=null){
            sb.append(temp.data+" ");
            temp = temp.next;
        }
        return sb.toString();
    }
    LinkedList(){
        head = null;
        tail = null;
    }
}

