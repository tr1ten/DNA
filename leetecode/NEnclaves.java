import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;

class Solution {
    public int numEnclaves(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        int[][] adj = {
            {0,1},{1,0},
            {0,-1},{-1,0}
        };
        Queue<int[]> q = new LinkedBlockingQueue<>();
        for (int i = 0; i < n; i++) {
            if(grid[i][0]==1) q.offer(new int[]{0,i});
            if(grid[i][m-1]==1) q.offer(new int[]{m-1,i});
            visited[i][0] = true;
            visited[i][m-1] = true;
        }
        for (int i = 0; i < m; i++) {
            if(grid[0][i]==1) q.offer(new int[]{i,0});
            if(grid[n-1][i]==1) q.offer(new int[]{i,n-1});
            visited[0][i] = true;
            visited[n-1][i] = true;

        }
        while (!q.isEmpty()) {
            int[] u = q.poll();
            int x=u[0],y=u[1];
            if(grid[y][x]==0) continue;
            for (int[] ad : adj) {
                int xi = x+ad[0],yi = y+ad[1];
                if(xi<0 || xi>=m || yi<0 || yi>=n || grid[yi][xi]==0 || visited[yi][xi]) continue;
                visited[yi][xi] = true;
                q.add(new int[]{xi,yi});
            }
        }
        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
}
