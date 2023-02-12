package Algos;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;

public class PrintingLCS {
    public List<String> getLCS(String text1,String text2,int[][] dp,int i,int j){
        if(i<=0 || j<=0) return Collections.singletonList("");
        List<String> res = new ArrayList<>();
        if(text1.charAt(i-1)==text2.charAt(j-1)){
            for(String x:getLCS(text1,text2,dp,i-1,j-1)){
                res.add(text1.charAt(i-1)+x); 
            }
        }   
        else{
            if(dp[i-1][j]>=dp[i][j-1]) res.addAll(getLCS(text1, text2, dp, i-1, j));
            if(dp[i-1][j]<=dp[i][j-1]) res.addAll(getLCS(text1, text2, dp, i, j-1));
        }
        return res;
    }
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
        // int i = text1.length();
        // int j = text2.length();
        // StringBuilder sb = new StringBuilder();
        // while (i>0 && j>0) {
        //     if(text1.charAt(i-1)==text2.charAt(j-1)){
        //         sb.append(text1.charAt(i-1));
        //         i--;
        //         j--;
        //     }   
        //     else{
        //         if(dp[i-1][j]>dp[i][j-1]) i--;
        //         else j--;
        //     }
        // }    
        int k=0;
        for(String x:new HashSet<>(getLCS(text1,text2,dp,text1.length(),text2.length()))){
            System.out.println((new StringBuilder(x)).reverse().toString());
            k++;
        }
        System.out.println("Total LCS: "+k);
        return "";
    }
    public static void main(String[] args) {
        PrintingLCS s = new PrintingLCS();
        System.out.println(s.longestCommonSubsequence("afgcfbce", "abcde"));
    }
}
