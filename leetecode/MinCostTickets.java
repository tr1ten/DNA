import java.util.Arrays;
import java.util.Collection;
import java.util.TreeSet;

// class Solution {
//     Integer[] dp;
//     int lower_bound(int array[], int key)
//     {
 
//         int index = Arrays.binarySearch(array, key);
 
//         if (index < 0) {
 
//             return Math.abs(index) - 1;
//         }
 
//         else {
//             while (index > 0) {
 
//                 if (array[index - 1] == key)
//                     index--;
 
//                 else
//                     return index;
//             }
 
//             return index;
//         }
//     }
//     int solve(int ind,int[] days,int[] cost){
//         if(ind>=days.length) return 0;
//         if(dp[ind]!=null) return dp[ind];
//         int w1 = solve(lower_bound(days, days[ind]+1), days, cost) + cost[0];
//         int w2 = solve(lower_bound(days, days[ind]+7), days, cost) + cost[1];
//         int w3 = solve(lower_bound(days, days[ind]+30), days, cost) + cost[2];
//         dp[ind] = Math.min(w2, Math.min(w1, w3));
//         return dp[ind];
//     }
//     public int mincostTickets(int[] days, int[] costs) {
//         int n = days.length;
//         dp  = new Integer[n];
//         return solve(0, days, costs);
//     }
// }

class Solution {
    public int mincostTickets(int[] days, int[] costs) {
        int[] dp = new int[366];
        int k =0,sum=0;
        for (int i = 1; i <=366; i++) {
            if(days[k]==i){
                k++;
                sum = Math.min(Math.min(costs[0]+dp[Math.max(0, i-1)], costs[1]+dp[Math.max(0, i-7)]), costs[2]+dp[Math.max(0, i-30)]);
            }
            dp[i] = sum;
        }
        return dp[365];
    }
}