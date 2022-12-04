import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import DS.QuickUnionWt;

class Solution {
    int bfs(int u,List<Integer>[] adj){
        Queue<Integer> q = new LinkedList<>();
        q.add(u);
        int l=0;
        boolean[] vis = new boolean[adj.length];
        vis[u] = true;
        while(!q.isEmpty()){
            int sz = q.size();
            boolean[] temp = new boolean[adj.length];
            while(sz-->0){
                int v = q.poll();
                temp[v] = true;
                for(int x:adj[v]){
                    if(temp[x]) return -1;
                    if(!vis[x]){
                        vis[x] = true;
                        q.add(x);
                    }
                }
            }
            l++;
        }
        return l;
    }
    public int magnificentSets(int n, int[][] edges) {
        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        QuickUnionWt q = new QuickUnionWt(n);
        for (int[] e : edges) {

            adj[e[0]-1].add(e[1]-1);
            adj[e[1]-1].add(e[0]-1);
            q.union(e[0]-1, e[1]-1);
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int p = q.find(i);
            int k = bfs(i,adj);
            if(k<0) return -1;
            map.put(p, Math.max(map.getOrDefault(p, 0),k));
        }
        return map.values().stream().mapToInt(x->x).sum();
        

    }
}