import java.util.HashMap;
import java.util.Map;

class LRUCache {
    class DNode{
        int key;
        DNode prev;
        DNode next;
        DNode(int k){
            this.key = k;
            prev =null;
            next = null;
        }
    }
    int cap;
    Map<Integer,DNode> keyToNode;
    DNode lastNode;
    DNode head;
    HashMap<Integer,Integer> cache;
    public LRUCache(int capacity) {
        cap = capacity;
        head = new DNode(-1);
        lastNode = head;
        cache = new HashMap<>();
        keyToNode = new HashMap<>();
        return;
    }
    DNode addNode(int key){
        if(keyToNode.containsKey(key)) return;
        DNode node = new DNode(key);
        lastNode.next = node;
        node.prev = lastNode;
        lastNode = node;
        lastNode.next = null;
        return node;
    }
    void putAtLast(int key){
        DNode node = keyToNode.get(key);
        deleteNode(key);
        node.prev = lastNode;
        lastNode.next = node;
        lastNode = node;
        lastNode.next = null;
    }
    void print(){
        DNode temp = head.next;
        while(temp!=null) {
            temp = temp.next;
        }
    }
    void deleteNode(int key){
        DNode node = keyToNode.get(key);
        if(node.key!=-1){
             node.prev.next= node.next;
             if(node.next!=null) node.next.prev = node.prev;
        }
    }
    public int get(int key) {
        if(cache.containsKey(key)){
            putAtLast(key);
            return cache.get(key);
        }
        return -1;
    }
    
    public void put(int key, int value) {
        if(!cache.containsKey(key)){
            if(cache.size()==cap) {
                int rmKey = head.next.key;
                cache.remove(rmKey);
                deleteNode(rmKey);
            }
        }
        else{
            putAtLast(key);
        }
        keyToNode.put(key, addNode(key));
        cache.put(key, value);
    }
}
