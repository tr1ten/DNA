class Trie {
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
    int sum(String word){
        int sum = 0;
        Node child = root;
        for (int i = 0; i < word.length(); i++) {
            sum +=child.cnt;
            int ind = word.charAt(i) - 'a';
            child = child.next[ind];
        }
        return sum;
    }

}

class Solution{
    public int[] sumPrefixScores(String[] words) {
        Trie trie = new Trie();
        for (String string : words) {
            trie.insert(string);
        }
        int[] arr = new int[words.length];
        int i =0;
        for (String w : words) {
            arr[i++] = trie.sum(w);
        }
        return arr;
    }
    
}
