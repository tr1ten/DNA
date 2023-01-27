import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {


    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Arrays.sort(words,(a,b)->a.length()-b.length());
        Trie tree = new Trie();
        ArrayList<String> res = new ArrayList<>();
        for (String w : words) {
            if(tree.recSearch(w)){
                res.add(w);
            }
            tree.insert(w);
        }
        return res;
    }
}



class Trie {
    class Node{
        Node[] next;
        boolean isEnd;
        Node(){
            next = new Node[26];
            isEnd = false;
        }
    }
    Node root;
    Trie(){
        root = new Node();
    }
    public void insert(String word){
        Node child = this.root;
        for (int i = 0; i < word.length(); i++) {
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
        if(node.isEnd){
            if((i<word.length() && node.next[ind]!=null && node.next[ind].isEnd) && (i+1==word.length() || _searchRec(root, i+1, word))) return true;
            if(_searchRec(root, i, word)) return true;
        }
        if(node.next[ind]==null) return  false;
        return _searchRec(node.next[ind], i+1, word);
    }
    public boolean recSearch(String word){
        return _searchRec(root, 0, word);
    }

}