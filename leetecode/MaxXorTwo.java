class Solution {
    public int findMaximumXOR(int[] nums) {
        Trie tr = new Trie();
        int mxxor = 0;
        int max = Integer.MIN_VALUE;
        for (int i : nums) max = Math.max(max, i);
        String mxw = Integer.toBinaryString(max);
        for (int x : nums) {
            String word = Integer.toBinaryString(x);
            int k = word.length();
            for(int i=0;i<mxw.length()-k;i++) word = '0'+word;
            mxxor = Math.max(x^(tr.maxXor(word,x)), mxxor);
            tr.insert(word,x);
        }
        return mxxor;

    }
}

class Trie {
    class Node{
        Node[] next;
        Integer num;
        Node(){
            next = new Node[2];
        }
    }
    Node root;
    Trie(){
        root = new Node();
    }
    void insert(String word,int num){
        Node child = this.root;
        for (int i = 0; i<word.length(); i++) {
            int ind = word.charAt(i) - '0';
            if(child.next[ind]==null){
                child.next[ind] = new Node();
            }
            child = child.next[ind];
        }
        child.num = num;
    }
    int maxXor(String word,int num){
        Node child = this.root;
        for (int i = 0; i<word.length(); i++) {
            int ind = (word.charAt(i) - '0')^1;
            if(child.next[ind]==null){
                ind ^=1;
            }
            if(child.next[ind]==null) return child.num==null ? num:child.num;
            child = child.next[ind];
        }
        return child.num==null?num:child.num;
    }

}

// solution 2
// greedily build the solution start from msb 31 to 0