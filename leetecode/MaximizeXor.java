import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class Solution {
    int MXBIT = 31;
    public int[] maximizeXor(int[] nums, int[][] queries) {
        Trie tr = new Trie(MXBIT);
        Arrays.sort(nums);
        List<Integer> ls = new ArrayList<>();
        for (int i = 0; i < queries.length; i++) {
            ls.add(i);
        }
        Collections.sort(ls,(a,b)->queries[a][1]-queries[b][1]);
        
        int[] res = new int[queries.length];
        int j=0;
        for (int i:ls) {
            int[] q = queries[i];
            int x = q[0];
            int m = q[1];
            while (j<nums.length && nums[j]<=m) {
                int xi = nums[j];
                String w = Integer.toBinaryString(xi);
                int k = w.length();
                for(int y=0;y<MXBIT-k;y++) w = '0'+w;
                tr.insert(w, xi);
                j++;
            }
            String word = Integer.toBinaryString(x);
            int k = word.length();
            for(int y=0;y<MXBIT-k;y++) word = '0'+word;
            int xor = tr.maxXor(word,x);
            if(xor==-1) res[i] = -1;
            else res[i]=x^(xor);
        }
        return res;
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
    int MXBIT;
    Trie(int mx){
        root = new Node();
        MXBIT = mx;
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
        for (int i =0; i<MXBIT; i++) {
            int ind = (word.charAt(i) - '0')^1;
            if(child.next[ind]==null){
                ind ^=1;
            }
            if(child.next[ind]==null) return child.num==null ? -1:child.num;
            child = child.next[ind];
        }
        return child.num==null?-1:child.num;
    }

}