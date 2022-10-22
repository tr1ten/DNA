import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.*;
class Solution {
    public long subArrayRanges(int[] arr) {
        Stack<Integer> st = new Stack<>();
        Stack<Integer> higherst = new Stack<>();
        int n = arr.length;
        int[] right = new int[n];
        int[] left = new int[n];
        int[] rightM = new int[n];
        int[] leftM = new int[n];
        
        for(int i=n-1;i>=0;i--){
            right[i] = n;
            rightM[i] = n;
            while(!st.isEmpty() && arr[st.peek()]>=arr[i]) st.pop();
            if(!st.isEmpty()) right[i] =st.peek();
            st.push(i);
            while(!higherst.isEmpty() && arr[higherst.peek()]<=arr[i]) higherst.pop();
            if(!higherst.isEmpty()) rightM[i] =higherst.peek();
            higherst.push(i);
        }
        st.clear();
        higherst.clear();
        for(int i=0;i<n;i++){
            left[i] = -1;
            leftM[i] = -1;
            while(!st.isEmpty() && arr[st.peek()]>arr[i]) st.pop();
            if(!st.isEmpty()) left[i] = st.peek();
            st.push(i);
            while(!higherst.isEmpty() && arr[higherst.peek()]>arr[i]) higherst.pop();
            if(!higherst.isEmpty()) leftM[i] = higherst.peek();
            higherst.push(i);
        }
        long max=0;
        long min = 0;
        for(int i=0;i<n;i++){
            max = (max + ((long)(i-leftM[i])*(rightM[i]-i)*arr[i]));
            min = (min + (long)(i-left[i])*(right[i]-i)*arr[i]);
        }
        return max-min;
    }
}