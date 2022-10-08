import java.util.HashMap;

class CutPizza {
    Integer[][][] hm;
    int[][] psd;
    static long MOD = 1000000007;
    int solve(String[] pizza, int si,int sj,int k,int ta){
        if(psd[si][sj]==0) return 0;
        int n=pizza.length;
        int m = pizza[0].length();
        if(si>=n || sj>=m) return 0;
        if(k<2) return 1;
        int[] key = new int[]{si,sj,k};
        if(hm[si][sj][k]!=null) return hm[si][sj][k]; 
        long cnt = 0;
        for(int i=si;i<n-1;i++){
            int appU = ta-psd[i+1][sj];
            if(appU>0 && psd[i+1][sj]>0){
                cnt +=solve(pizza,i+1,sj,k-1,psd[i+1][sj]);
                cnt %=MOD;
            }        
        }
        for(int i=sj;i<m-1;i++){
            int lfa = ta - psd[si][i+1];
            if(lfa>0 && psd[si][i+1]>0){
                cnt +=solve(pizza,si,i+1,k-1,psd[si][i+1]);
                cnt %=MOD;
            }
        }
        hm[si][sj][k] = (int)cnt;
        return hm[si][sj][k];
    }
    int getC(String[] pizza,int i,int j){
        return pizza[i].charAt(j) == 'A' ? 1 : 0;
    }
    public int ways(String[] pizza, int k) {
        int n = pizza.length;
        int m = pizza[0].length();
        hm = new Integer[k][m][n];
        psd = new int[n][m];
        psd[n-1][m-1] = getC(pizza,n-1,m-1);
        for(int i=n-2;i>=0;i--) psd[i][m-1] +=(psd[i+1][m-1] + getC(pizza,i,m-1));
        for(int i=m-2;i>=0;i--) psd[n-1][i] +=(psd[n-1][i+1] + getC(pizza,n-1,i));
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                psd[i][j] = (psd[i+1][j] + psd[i][j+1] - psd[i+1][j+1] + getC(pizza,i,j));
            }
        }
        return solve(pizza,0,0,k,psd[0][0]);

    }
    public static void main(String[] args) {
        CutPizza s = new CutPizza();
        String[] pizza = new String[]{"A..","AAA","..."};
        int k = 3;
        System.out.println(s.ways(pizza,k));
    }
}