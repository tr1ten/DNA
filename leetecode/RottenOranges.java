import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.*;
class Solution {
    int bfs(int[][] grid){
        Queue<int[]> q = new LinkedBlockingQueue<>();
        int n = grid.length;
        int m = grid[0].length;
        int[][] adj = {{0,-1},{-1,0},{1,0},{0,1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               if(grid[i][j]==2) q.offer(new int[]{i,j,0});
            }
        }
        int mxLvl = 0;
        while (!q.isEmpty()) {
            int[] g = q.poll();
            int x=g[1],y=g[0],lbl=g[2];
            mxLvl = Math.max(mxLvl, lbl);
            for (int[] ad : adj) {
                int xi=x+ad[1],yi=y+ad[0];
                if((xi>=m || yi>=n || xi<0 || yi<0) || grid[yi][xi]!=1){
                    continue;
                }
                grid[yi][xi] = 3;
                q.offer(new int[]{yi,xi,lbl+1});
            }
        }
        return mxLvl;
    }
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int lvl = bfs(grid);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1) return -1;
            }
        }
        return lvl;

    }
}