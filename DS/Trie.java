package DS;

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
    boolean _searchRec(Node node,int i,String word){
        if(i>=word.length()) return node.isEnd;
        int ind = word.charAt(i)-'a';
        if(node.next[ind]==null) return  false;
        return _searchRec(node.next[ind], i+1, word);
    }
    boolean recSearch(String word){
        return _searchRec(root, 0, word);
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
        assert t.recSearch("hello");
        assert t.recSearch("hell");
        assert t.recSearch("world");
        assert !t.recSearch("helo");
        assert !t.recSearch("h");
        assert !t.recSearch("helloo");
        assert !t.recSearch("helloo");
        assert !t.recSearch("helloo");
        assert !t.recSearch("helloo");
    }

}
