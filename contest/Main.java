import java.io.*;
import java.util.*;
public class Main
{
        //     public static void main(String args[]) throws Exception
        //     {
        //             Scanner cin=new Scanner(System.in);
        //             int t = cin.nextInt();
        //             while (t-->0) {
        //                 int res=0;
        //                 String s = cin.next();
        //                 int n = s.length();
        //                 int[] count = new int[26];
        //                 for (int i = 0; i < s.length(); i++) {
        //                     count[s.charAt(i) - 'a']++;
        //                 }
        //                 for (int i = 0; i < 26; i++) {
        //                         if(count[i]<2) continue;
        //                         int r = count[i]/2;
        //                         while (r-->0 && n>0) {
        //                                 res++;
        //                                 n -=3;
        //                         } 
        //                 }
        //                 System.out.println(res);
        //             }
        //     }

        // static String solve(int x,int y,int[][] maze,int[] end,String s){
        //         if(x==end[0] && y==end[1]) return s;
        //         if(x<0 || y<0 || x>=maze.length || y>=maze[0].length || maze[x][y]==1) return "";
        //         maze[x][y] = 1;
        //         String res = solve(x+1,y,maze,end,s+"D");
        //         if(res.length()>0) return res;
        //         res = solve(x,y-1,maze,end,s+"L");
        //         if(res.length()>0) return res;
        //         res = solve(x,y+1,maze,end,s+"R");
        //         if(res.length()>0) return res;
        //         res = solve(x-1,y,maze,end,s+"U");
        //         if(res.length()>0) return res;
        //         return "";
        // }
        // public static void main(String[] args) {
        //         Scanner cin=new Scanner(System.in);
        //         int m,n;
        //         n=cin.nextInt();
        //         m=cin.nextInt();
        //         int[] start = new int[2];
        //         int[] end = new int[2];
        //         int[][] a=new int[n][m];
        //         for(int i=0;i<n;i++){
        //                 String s = cin.next();
        //                 for(int j=0;j<m;j++){
        //                         char c = s.charAt(j);
        //                         if(c=='A'){
        //                                 start[0] = i;
        //                                 start[1] = j;
        //                         }
        //                         if(c=='B'){
        //                                 end[0] = i;
        //                                 end[1] = j;
        //                         }
        //                         a[i][j] = c=='#'?1:0;
        //                 }
        //         }
        //         String res = solve(start[0],start[1],a,end,"");
        //         if(res.length()==0){
        //                 System.out.println("NO");
        //         }else{
        //                 System.out.println(res.length());
        //                 System.out.println(res);
        //         }
        //         cin.close();
        // }
        static String longestCommonSubsequence(String text1, String text2,int target) {
                int[][] dp = new int[text1.length()+1][text2.length()+1];
                int mxi = text1.length(),mxj=text2.length();
                for (int i = 1; i <=text1.length(); i++) {
                    for (int j = 1; j <=text2.length(); j++) {
                        if(text1.charAt(i-1) == text2.charAt(j-1)){
                            dp[i][j] = dp[i-1][j-1]+1;  
                        }
                        else dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
                        // if(dp[i][j]==target){
                        //         mxi = i;
                        //         mxj = j;
                        // }
                    }
                }
                int i = text1.length();
                int j = text2.length();
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
                Scanner cin=new Scanner(System.in);
                String s1 = cin.next();
                // reverse 
                String s2 = new StringBuilder(s1).reverse().toString();
                String res = longestCommonSubsequence(s1,s2,s1.length()/2);
                if(res.length()<s1.length()/2){
                        System.out.println("Impossible");
            }
            else{
                System.out.println(s1.length()-res.length());
            }
}