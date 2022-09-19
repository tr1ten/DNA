public class Trie {
    class Node{
        // child nodes 26
        Node[] next;
        // is this end of the word?
        boolean isEnd;
        // how many times letter appears
        int cnt;
        Node(){
            next = new Node[26];
            isEnd = false;
            cnt = 0;
        }
    }
    Node root;
    Trie(){
        root = new Node();
    }
    // assuming all lowercase chars
    void insert(String word){
        Node child = this.root;
        for (int i = 0; i < word.length(); i++) {
            child.cnt++;
            int ind = word.charAt(i) - 'a';
            if(child.next[ind]==null){
                child.next[ind] = new Node();
            }
            child = child.next[ind];
        }
        child.isEnd = true;
    }
    boolean search(String word){
        Node child = this.root;
        for (int i = 0; i < word.length(); i++) {
            int ind = word.charAt(i) - 'a';
            if(child.next[ind]==null){
                return false;
            }
            child = child.next[ind];
        }
        return child.isEnd;
    }
    // unit test 
    public static void main(String[] args) {
        Trie t = new Trie();
        t.insert("hello");
        t.insert("hell");
        t.insert("world");
        assert t.search("hello");
        assert t.search("hell");
        assert t.search("world");
        assert !t.search("helo");
        assert !t.search("h");
        assert !t.search("helloo");
        assert !t.search("helloo");
        assert !t.search("helloo");
        assert !t.search("helloo");
    }

}
