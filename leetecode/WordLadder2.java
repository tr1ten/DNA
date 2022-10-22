import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;
class Solution {
    List<List<String>> res;
    List<String> wordList;
    boolean isNext(String s,String t){
        int cnt=0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)!=t.charAt(i)) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
    void dfs(int u,int target,List<Integer>[] graph,Stack<String> visited){
    visited.add(wordList.get(u));
    if(u==target){
        res.add(new ArrayList<>(visited));
    }
    for(int v:graph[u]) {
        dfs(v,target,graph,visited);
    }
    visited.remove(wordList.get(u));
}

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        int target = wordList.indexOf(endWord);
        res = new ArrayList<>();
        if(target<0) return res;
        if(!wordList.contains(beginWord)) wordList.add(beginWord);
        int n = wordList.size();
        this.wordList = wordList;
        int src = wordList.indexOf(beginWord);
        // adjacency list
        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < adj.length; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(isNext(wordList.get(i), wordList.get(j))){
                    adj[i].add(j);
                    adj[j].add(i);
                }
            }
        }
        // bfs to find shortest path
        int[] distTo = new int[n];
        Arrays.fill(distTo, Integer.MAX_VALUE);
        Queue<Integer> q = new LinkedBlockingQueue<>();
        distTo[src] = 0;
        List<Integer>[] edgeTo = new ArrayList[n];
        for (int i = 0; i < edgeTo.length; i++) {
            edgeTo[i] = new ArrayList<>();
        }
        q.offer(src);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj[u]) {
                if(distTo[v]>distTo[u]+1) {
                    q.offer(v);
                    edgeTo[v].add(u);
                    distTo[v] = distTo[u]+1;
                }
                else if(distTo[v]==distTo[u]+1){
                    edgeTo[v].add(u);
                }
            }
        }
        System.out.println(Arrays.toString(edgeTo));
        dfs(target, src, edgeTo, new Stack<>());  
        return res;
    }
}