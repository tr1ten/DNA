import java.util.Arrays;

public class MaxAreaIsland {
    int[][] grid;
    int[][] mem;
    int w;
    int h;
    private int solve(int x,int y,boolean[][] visited){
        if(x<0 || y<0 || x>=w || y>=h) return 0;
        if(visited[y][x]) return 0;
        if(mem[y][x]>0) return mem[y][x];
        if(grid[y][x]!=1) return 0;
        visited[y][x] = true;
        mem[y][x] = 1 + solve(x+1,y,visited) + solve(x-1,y,visited) + solve(x,y+1,visited) + solve(x,y-1,visited);
        return mem[y][x];
        
    }
    public int maxAreaOfIsland(int[][] grid) {
        this.grid = grid;
        w = grid[0].length;
        h = grid.length;
        boolean[][] visited = new boolean[h][w];
        mem = new int[h][w];
        int mc = 0;
        for(int y=0;y<h;y++){
            for(int x=0;x<w;x++){
                mc = Math.max(mc, solve(x,y,visited));
            }
        }
        for(int y = 0;y<h;y++){
        System.out.println(Arrays.toString(mem[y]));
        }
        return mc;

    }
    public static void main(String[] args) {
        MaxAreaIsland s = new MaxAreaIsland();
        int[][] grid = new int[][]{
            {1,1,0,0,0},
            {1,1,0,0,0},
            {0,0,0,1,1},
            {0,0,0,1,1}
        };
        System.out.println(s.maxAreaOfIsland(grid));
    }
}