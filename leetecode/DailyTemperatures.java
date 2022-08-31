import java.util.*;
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> st = new Stack<>();
        int n = temperatures.length;
        int[] sols = new int[n];
        for(int i=0;i<n;i++){
            while(!st.empty() && st.peek()<temperatures[i]){
                int j = st.pop();
                sols[j] = i-j;
            }
            st.push(i);
        }
        return sols;
        
    }
}