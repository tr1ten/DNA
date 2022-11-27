import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;

class Solution {
    public int shortestPathLength(int[][] graph) {
        int n = graph.length;
        if(n==1) return 0;
        Queue<int[]> q = new LinkedBlockingQueue<>(); // will maintain the current visited node
        for (int i = 0; i < n; i++) {
            q.add(new int[]{i,(1<<i)});
        }
        int finalState = (1<<n) - 1;
        boolean[][] mem = new boolean[n][finalState+1]; // so that we don't repeat path indefinetly, store node with its state
        int sp = 0; // ans
        while (!q.isEmpty()) {
            int sz = q.size();
            sp++;
            for (int i = 0; i < sz; i++) {
                int[] el = q.poll();
                int u = el[0],currentState = el[1];
                for (int v : graph[u]) {
                    int nextState = currentState | (1<<v);
                    if(mem[v][nextState]) continue;
                    if(nextState==finalState) return sp;
                    mem[v][nextState] = true;
                    q.add(new int[]{v,nextState});
                }
            }
        }
        return Integer.MAX_VALUE;
    }
}