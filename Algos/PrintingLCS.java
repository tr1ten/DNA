package Algos;


public class PrintingLCS {
    public String longestCommonSubsequence(String text1, String text2) {
        int[][] dp = new int[text1.length()+1][text2.length()+1];
        for (int i = 1; i <=text1.length(); i++) {
            for (int j = 1; j <=text2.length(); j++) {
                if(text1.charAt(i-1) == text2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1]+1;  
                }
                else dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i = text1.length();
        int j = text2.length();
        // print dp with text1 chars
        System.out.print("  ");
        for (int k = 0; k < text2.length(); k++) {
            System.out.print(text2.charAt(k)+" ");
        }
        System.out.println();
        for (int k = 1; k < dp.length; k++) {
            if(k!=0) System.out.print(text1.charAt(k-1)+" ");
            for (int l = 1; l < dp[0].length; l++) {
                System.out.print(dp[k][l]+" ");
            }
            System.out.println();
        }
        StringBuilder sb = new StringBuilder();
        while (i>0 && j>0) {
            if(text1.charAt(i-1)==text2.charAt(j-1)){
                sb.append(text1.charAt(i-1));
                i--;
                j--;
            }   
            else{
                if(dp[i-1][j]>dp[i][j-1]) i--;
                else j--;
            }
        }
        return sb.reverse().toString();
    }
    public static void main(String[] args) {
        PrintingLCS s = new PrintingLCS();
        System.out.println(s.longestCommonSubsequence("abac", "cab"));
    }
}
