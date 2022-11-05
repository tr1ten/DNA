import java.util.*;
class Trie {
    class Node{
        // child nodes 26
        Node[] next;
        // is this end of the word?
        boolean isEnd;
        boolean founded;
        String key;
        // how many times letter appears
        Node(){
            next = new Node[26];
            isEnd = false;
            founded = false;
        }
    }
    Node root;
    List<String> found;
    Trie(){
        root = new Node();
        found = new ArrayList<>();
    }
    // assuming all lowercase chars
    void insert(String word){
        Node child = this.root;
        for (int i = 0; i < word.length(); i++) {
            int ind = word.charAt(i) - 'a';
            if(child.next[ind]==null){
                child.next[ind] = new Node();
            }
            child = child.next[ind];
        }
        child.isEnd = true;
        child.key = word;
    }
    void res(char[][] mat,int x,int y,Node node,boolean[][] visited){
        if(node.isEnd && !node.founded){
             found.add(node.key);
            node.founded = true;
            }
        int[][] adj = {{1,0},{0,1},{-1,0},{0,-1}};
        visited[y][x] = true;
        for (int[] a : adj) {
            int xi = x+a[0],yi = y+a[1];
            if(xi<0 || xi>=mat[0].length || yi<0 || yi>=mat.length || node.next[mat[yi][xi]-'a']==null || visited[yi][xi]) continue;
            visited[yi][xi] =true;
            res(mat, xi, yi, node.next[mat[yi][xi]-'a'],visited);
            visited[yi][xi] =false;
        }
    }
    void search(char[][] board,int i,int j){
            if(root.next[board[i][j]-'a']==null) return;
            boolean[][] visited = new boolean[board.length][board[0].length];
            visited[i][j] = true;
            res(board, j, i, root.next[board[i][j]-'a'],visited);
        }

}

class Solution {
    public List<String> findWords(char[][] board, String[] words) {
        int n = board.length;
        int m = board[0].length;
        Trie tr = new Trie();
        for (String w : words) {
            tr.insert(w);            
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tr.search(board,i,j);
            }
        }
        return tr.found;

    }
}