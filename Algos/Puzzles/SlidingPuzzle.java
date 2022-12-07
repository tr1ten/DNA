import java.util.HashMap;
import java.util.Map;

/**
 * SlidingPuzzle
 */
 class SlidingPuzzle2 {
    boolean isSolved(int[][] state){
        int n = state.length;
        int m = state[0].length;
        int cnt = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==n-1 && j==m-1) return state[i][j]==0;
                if(state[i][j]!=cnt++) return false;
            }
        }
        return true;
    }
    void swap(int[][] state,int y,int x,int yi,int xi){
        int temp = state[y][x];
        state[y][x] = state[yi][xi];
        state[yi][xi] = temp;
    }
    HashMap<String,Integer> mem;
    int solve(int i,int j,int[][] state){
        int n = state.length;
        int m = state[0].length;
        String l=j-1<0 ? "0" : Integer.toString(state[i][j-1]);
        String r=j+1>=m ? "0" : Integer.toString(state[i][j+1]);
        String u=i-1<0 ? "0" : Integer.toString(state[i-1][j]);
        String d=i+1>=n ? "0" : Integer.toString(state[i+1][j]);
        String key = Integer.toString(i) + Integer.toString(j) + l+r+u+d;
        if(mem.containsKey(key)) return mem.get(key);
        if(isSolved(state)) {
            mem.put(key, 0);
            return 0;
        }
        int[][] adj = {{-1,0},{0,-1},{0,1},{1,0}};
        int res = Short.MAX_VALUE;
        mem.put(key, res);
        for(int[] a:adj){
            int yi=a[0]+i,xi=a[1]+j;
            if(yi<0 || yi>=n || xi<0 || xi>=m) continue;
            swap(state, yi, xi, i, j);
            res = Math.min(1+solve(yi, xi, state), res); 
            swap(state, yi, xi, i, j);
            
        }
        mem.put(key, res>=Short.MAX_VALUE ? Integer.MAX_VALUE : res);
        return res;
    }
    public int slidingPuzzle(int[][] board) {
        int n = board.length;
        int m = board[0].length;
        mem = new HashMap<>();
        int y=-1;
        int x=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==0){
                    y = i;
                    x = j;
                    break;
                }
            }
        }
        int res = solve(y, x, board);
        return res>=Short.MAX_VALUE ? -1 : res;
    }
    public static void main(String[] args) {
        SlidingPuzzle sp = new SlidingPuzzle();
        int[][] board = {{4,1,2},{5,0,3}}; // [[4,1,2],[5,0,3]]
        System.out.println(sp.slidingPuzzle(board));
    }
}