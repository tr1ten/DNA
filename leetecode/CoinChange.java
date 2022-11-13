import java.util.Arrays;

class CoinChange {
    public int coinChange(int[] coins, int amount) {
        int[][] dp = new int[coins.length+1][amount+1];
        for(int i=1;i<=amount;i++) dp[0][i]=Integer.MAX_VALUE;
        for(int i=1;i<=coins.length;i++){
            for(int j=1;j<=amount;j++){
                if(j<coins[i-1]) dp[i][j]=dp[i-1][j];
                else{
                    if(dp[i-1][j]==Integer.MAX_VALUE && dp[i][j-coins[i-1]]==Integer.MAX_VALUE) dp[i][j]=Integer.MAX_VALUE;
                    else if(dp[i-1][j]==Integer.MAX_VALUE) dp[i][j]=dp[i][j-coins[i-1]]+1;
                    else if(dp[i][j-coins[i-1]]==Integer.MAX_VALUE) dp[i][j]=dp[i-1][j];
                    else dp[i][j]=Math.min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                }
            }
        }
        return dp[coins.length][amount]==Integer.MAX_VALUE ? -1 : dp[coins.length][amount];
    }
    public static void main(String[] args) {
        CoinChange s = new CoinChange();
        int[] coins = {2};
        int amount = 3;
        System.out.println(s.coinChange(coins, amount));
    }
}