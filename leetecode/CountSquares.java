class Solution {
    public int countSquares(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] psd = new int[n+1][m+1];
        psd[n-1][m-1] = matrix[n-1][m-1];
        for(int i=n-2;i>=0;i--) psd[i][m-1] +=(psd[i+1][m-1] + matrix[i][m-1]);
        for(int i=m-2;i>=0;i--) psd[n-1][i] +=(psd[n-1][i+1] + matrix[n-1][i]);
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                psd[i][j] = (psd[i+1][j] + psd[i][j+1] - psd[i+1][j+1] + matrix[i][j]);
            }
        }
        int mxsz = Math.min(n, m);
        int res=0;
        for (int sz = 1; sz <=mxsz; sz++) {
            int i=0,j=0;
            while (i+sz<=n && j+sz<=m) {
                
                if(psd[i][j]+psd[i+sz][j+sz]-psd[i+sz][j]-psd[i][j+sz]==sz*sz) res++;
                j++;
                if(j+sz-1==m){
                    j=0;
                    i++;
                }
            }
        }
        return res;
    }
}
// lee's
class Solution2 {
    public int countSquares(int[][] A) {
        int res=0;
        for(int i=0;i<A.length;i++){
            for(int j=0;j<A[0].length;j++){
                if(i>0 && j>0 && A[i][j]>0) A[i][j] = Math.min(A[i-1][j-1],Math.min(A[i][j-1],A[i-1][j])) + 1;
                res += A[i][j];
            }       
        }
        return res;
    }
}