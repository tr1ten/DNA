import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    static void countSort(int[] A,int e,int k){
        int[] cnt = new int[k];
        for (int i = 0; i < A.length; i++) {
            cnt[(A[i]+10000)]++; 
        } 
        for (int i = 1; i < k; i++) {
            cnt[i] = cnt[i-1] + cnt[i];
        }
        int[] temp = new int[A.length];
        for (int i = A.length-1; i>=0; i--) {
            temp[--cnt[(A[i]+10000)]] = A[i];
        }
        for (int i = 0; i < temp.length; i++) {
            A[i] = temp[i];
        }
    }
    public int arrayPairSum(int[] A) {
        countSort(A, 1, 20001);
        int sum=0;
        for (int i = 0; i < A.length; i+=2) {
            sum+=A[i];
        }
        return sum;
    }
}