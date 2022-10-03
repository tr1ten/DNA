package DS;


class TestRBT{
    public static void main(String[] args) {
        RedBlackBST<String, Integer> st = new RedBlackBST<String, Integer>();
        st.put("A", 1);
        st.put("B", 2);
        st.put("C", 3);
        st.put("D", 4);
        st.put("E", 5);
        st.put("F", 6);
        st.put("G", 7);
        System.out.println(st.get("F"));
        
}
}
public class RedBlackBST<K extends Comparable<K>,V> {
    Node<K,V> root;
    RedBlackBST(){
        this.root = null;
    }
    private void leftShift(Node<K,V> node){
        assert node.right!=null;
        assert node.left.color;
        Node<K,V> right = node.right;
        right.left = node;
        node.right = right.left;
        right.color = false;
        node.color = true;
    }
    private void rightShift(Node<K,V> node){
        assert node.left!=null;
        assert node.left.color;
        Node<K,V> left = node.left;
        left.left = node;
        node.left = left.left;
        left.color = false;
        node.color = true;
    }
    private void flipColors(Node<K,V> node){
        assert node.left.color;
        assert node.right.color;
        node.left.color = false;
        node.right.color = false;
        node.color = true;
    }
    private Node<K,V> search(Node<K,V> root,K key){
        if(root==null) return null;
        if(root.key.compareTo(key)==0) return root;
        if(root.key.compareTo(key)<0) return search(root.right, key);
        return search(root.left, key);
    }
    private Node<K,V> _insert(Node<K,V> node,K key,V value){
        if(node==null) return new Node<K,V>(key, value, true);
        if(node.key.compareTo(key)<0) node.right = _insert(node.right, key,value);
        else node.left = _insert(node.left, key,value);
        // balance the tree
        if(node.left==null || node.right==null) return node;
        if(node.right.color && !node.left.color) leftShift(node);
        if(node.left.color && node.left.left.color) rightShift(node);
        if(node.left.color && node.right.color) flipColors(node);
        return node;
    }
    public void put(K key,V value){
        this.root = _insert(root, key, value);
    }
    public V get(K key){
        Node<K,V> node = search(root, key);
        if(node==null) return null;
        return node.value;
    }
}

class Node<K,V>{
    K key;
    V value;
    Node<K,V> left;
    Node<K,V> right;
    boolean color; // red - true, black - false
    
    public Node(K key, V value, boolean color) {
        this.key = key;
        this.value = value;
        this.color = color;
    }
}