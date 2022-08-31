class SolveSudoku {
    boolean[][] rowVisit;
    boolean[][] colVisit;
    boolean[][] cellVisit;
    int nrow;
    int ncol;
    boolean solved;
    char[][] board;
    private boolean isValid(int r,int c,int val){
        return !rowVisit[r][val-1] && !colVisit[c][val-1] && !cellVisit[3*(r/3) + c/3][val-1]; 
    }
    private void putValue(int r,int c,int val){
            rowVisit[r][val-1] = true;
        colVisit[c][val-1] = true;
        cellVisit[3*(r/3) + c/3][val-1] = true;
        board[r][c] = (char)(val+'0');  
    }
    private void removeValue(int r,int c,int val){
            rowVisit[r][val-1] = false;
        colVisit[c][val-1] = false;
        cellVisit[3*(r/3) + c/3][val-1] = false;
        board[r][c] = '.';   
    }
     public boolean isValidSudoku() {
        nrow = 9;
        ncol = 9;
         rowVisit = new boolean[nrow][];
         colVisit = new boolean[ncol][];
         cellVisit = new boolean[nrow][];
        for(int i=0;i<nrow;i++){
            boolean[] visited = new boolean[nrow];
            boolean[] visited2 = new boolean[ncol];
            for(int j=0;j<ncol;j++){
                int a = board[i][j] - '1';
                int b = board[j][i] - '1';
                if(board[i][j]!='.'){
                    if(visited[a]) return false;
                    visited[a] = true;
                
                }
                if(board[j][i]=='.') continue;
                if(visited2[b]) return false;
                visited2[b] = true;
                
            }
            rowVisit[i] = visited;
            colVisit[i] = visited2;
        }
        int k=0;
        for(int sr=0;sr<nrow;sr+=3){
            for(int sc=0;sc<ncol;sc+=3){
                boolean[] visited = new boolean[nrow];
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++)
                    {
                            if(board[sr+i][sc+j]=='.') continue;
                            int a = board[sr + i][sc +j] - '1';
                            if(visited[a]) return false;
                           visited[a] = true;
                    }
                }
                cellVisit[k++] = visited;

            }
            
        }
        return true;
    }
    private void rec(int r,int c)
    {
        if(solved) return;
        if(r>=nrow) {
            solved = true;
            return;
        }
        if(c>=ncol){
            rec(r+1,0);
            return;
        }
        if(board[r][c]!='.') {
            rec(r,c+1);
            return;
        }
        
        for(int i=1;i<10;i++){
            if(isValid(r,c,i)){
               board[r][c] = (char)('0' + i);
                putValue(r,c,i);
                rec(r,c+1);
                removeValue(r,c,i);
                }
        }
        
    }
    public void solveSudoku(char[][] board) {
        this.board = board;
        isValidSudoku();
        rec(0,0);
    }
    public static void main(String[] args) {
         SolveSudoku solver = new SolveSudoku();
         solver.solveSudoku(new char[][]{
             {'5','3','.','.','7','.','.','.','.'},
             {'6','.','.','1','9','5','.','.','.'},
             {'.','9','8','.','.','.','.','6','.'},
             {'8','.','.','.','6','.','.','.','3'},
             {'4','.','.','8','.','3','.','.','1'},
             {'7','.','.','.','2','.','.','.','6'},
             {'.','6','.','.','.','.','2','8','.'},
             {'.','.','.','4','1','9','.','.','5'},
             {'.','.','.','.','8','.','.','7','9'}
         });
    }
}