
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.TreeMap;
class TreeNode {
    TreeNode right;
    TreeNode left;
    int val;
    TreeNode(int val) {this.val = val;}
    TreeNode(int val,TreeNode r,TreeNode l) {
        this.val = val;
        this.right = r;
        left = l;
    }

}
class Solution {
    public int[] sumPrefixScores(String[] words) {
        HashMap<String,Integer> hm = new HashMap<>();
        // sort words first by alphabetical order
        Arrays.sort(words); 
        int[] arr = new int[words.length];
        int p2=0;
        for (int i = 0; i < arr.length; i++) {
            String word = words[i];
            int j=i+1;
            int s = word.length();
            while(j<words.length )
        }
        

        return arr;
    }
    public int[] sumPrefixScores2(String[] words) {
        HashMap<String,Integer> hm = new HashMap<>();
        for (String word : words) {
            String sb = "";
            // optimize
            for (int i = 0; i < word.length(); i++) {
                sb +=  word.charAt(i);
                hm.put(sb, hm.getOrDefault(sb, 0) + 1);
            }
        }
        int[] arr = new int[words.length];
        int i =0;
        for (String word : words) {
            // optimize this
            int sum = 0;
            String sb = "";
            for (int j = 0; j < word.length(); j++) {
                sb += word.charAt(j);
                sum += hm.get(sb);
            }
            arr[i++] = sum;
        }
        return arr;
    }
    // write above function in more efficient way
    
}

class Solution2 {
    public int[] sumPrefixScores(String[] words) {
        
        Trie root = new Trie();
        for (String s : words) {
            root.add(s);
        }
        
        int[] ans = new int[words.length];
        for (int i = 0; i < ans.length; i++) {
            ans[i] = root.sum(words[i], 0);
        }

        return ans;
    }

    private class Trie {
        private Trie[] next;
        private boolean isWord;
        private int cnt;

        private Trie() {
            next = new Trie[26];
            isWord = false;
        }

        private void add(String s) {
            add(s, 0);
        }

        private void add(String s, int k) {
            cnt++;
            if (k == s.length()) {
                isWord = true;
            } else {
                char c = s.charAt(k);
                if (next[c - 'a'] == null) {
                    next[c - 'a'] = new Trie();
                }
                next[c - 'a'].add(s, k + 1);
            }
        }
        private int sum(String s, int k) {
            if (k == s.length()) {
                return cnt;
            } 
            char c = s.charAt(k);
            if (k == 0) {
                return next[c - 'a'].sum(s, k + 1);
            }
            return cnt + next[c - 'a'].sum(s, k + 1);
            
        }

    }
}
