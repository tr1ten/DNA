import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;
class Solution {
    public int largestIsland(int[][] grid) {
        List<int[]> edges = new ArrayList<>();
        Queue<int[]> q = new LinkedBlockingQueue<>();
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        int[][] adj = {{0,-1},{-1,0},{1,0},{0,1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(visited[i][j]) continue;
                visited[i][j] = true;
                q.clear();
                q.add(new int[]{i,j});
                while (!q.isEmpty()) {
                    int[] pt = q.peek();
                    for (int[] a:adj) {
                        int[] pti = new int[]{pt[0]+a[0],pt[1]+a[1]};
                        if(!visited[pti[0]][pti[1]]){
                            visited[pti[0]][pti[1]] = true;
                            q.add(pti);
                            edges.add(, pt);
                        }
                    }
                }
            }
        }

    }
}