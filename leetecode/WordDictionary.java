public class WordDictionary {
    class Node{
        Node[] next;
        boolean isEnd;
        Node(){
            next = new Node[26];
            isEnd = false;
        }
    }
    Node root;
    WordDictionary(){
        root = new Node();
    }
    // assuming all lowercase chars
    void addWord(String word){
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
        if(word.charAt(i)=='.'){
            for (int j = 0; j < 26; j++) {
                if(node.next[i]!=null){
                    if(_searchRec(node, i+1, word)) return true;                    
                }
            }
            return false;
        }
        int ind = word.charAt(i)-'a';
        if(node.next[ind]==null) return false;
        return _searchRec(node.next[ind], i+1, word);
    }
    boolean search(String word){
        return _searchRec(root, 0, word);
    }
}
