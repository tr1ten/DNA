import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;

class Solution {
    boolean isNext(String s,String t){
        int cnt=0;
        for (int i = 0; i < s.length(); i++) {
            if(s.charAt(i)!=t.charAt(i)) cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
    public int ladderLength(String beginWord, String endWord, List<String> wordList)    {
        int target = wordList.indexOf(endWord);
        if(target<0) return 0;
        if(!wordList.contains(beginWord)) wordList.add(beginWord);
        int n = wordList.size();
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
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedBlockingQueue<>();
        distTo[src] = 0;
        visited[src] =true;
        q.offer(src);
        while (!q.isEmpty()) {
            int u = q.poll();
            if(u==target) return distTo[u];
            for (int v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.offer(v);
                    distTo[v] = distTo[u]+1;
                }
            }
        }
        return 0;
    }
}