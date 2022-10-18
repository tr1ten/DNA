import java.util.*;
class WordFilter {
    public class Node{
        Node[] next;
        int key;
        Node(){
            next = new Node[27];
            key = -1;
        }
    }
    class Trie{
        Node root;
        Trie(){
            root = new Node();
        }
        // assuming all lowercase chars
        void insert(String word,int key){
            Node child = this.root;
            for (int i = 0; i < word.length(); i++) {
                int ind = word.charAt(i) - 'a';
                if(child.next[ind]==null){
                    child.next[ind] = new Node();
                }
                child = child.next[ind];
            }
            child.key = key;
        }
        int _searchRec(Node node,int i,String word){
            if(i==word.length()) return node.key;
            int ind = word.charAt(i)-'a';
            if(node.next[ind]==null) return -1;
            return _searchRec(node.next[ind], i+1, word);
        }
        int recSearch(String word){
            return _searchRec(root, 0, word);
        }
    }
    Trie trie;
    Trie reverseTrie;
    public WordFilter(String[] words) {
        trie = new Trie();
        for (int i = 0; i < words.length; i++) {
            String word = '{' + words[i];
            trie.insert(word, i);
            for (int j = 0; j <word.length(); j++) {   
                trie.insert(word.substring(j+1)+word, i);
            }
        }
    }
    public int f(String pref, String suff) {
        return trie.recSearch(suff+'{'+pref);
    }
}
