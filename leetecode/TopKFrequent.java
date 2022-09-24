import java.security.KeyStore.Entry;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Set;

class TopKFrequent {
    static int max(int[] a){
        int max = Integer.MIN_VALUE;
        for(int i=0;i<a.length;i++){
            if(a[i]>max)
                max = a[i];
        }
        return max;
    }
    static void countSort(int[][] A,int e,int k){
        int[] cnt = new int[k];
        for (int i = 0; i < A.length; i++) {
            cnt[(A[i][1]/e)%k]++; 
        } 
        for (int i = 1; i < k; i++) {
            cnt[i] = cnt[i-1] + cnt[i];
        }
        int[][] temp = new int[A.length][2];
        for (int i = A.length-1; i>=0; i--) {
            temp[--cnt[(A[i][1]/e)%k]] = A[i];
        }
        for (int i = 0; i < temp.length; i++) {
            A[i] = temp[i];
        }
    }

    public int[] topKFrequent(int[] A, int k) {
        HashMap<Integer,Integer> hm = new HashMap<>();
        int m = 0;
        for (int a:A) {
            int c = hm.getOrDefault(a, 0)+1;
            m = Math.max(c, m);
            hm.put(a, c);
        }
        int[][] arr = new int[hm.size()][2];
        int i=0;
        for(var entry:hm.entrySet()){
            arr[i][1] = entry.getValue();
            arr[i++][0] = entry.getKey();
        }
        for (int e = 1; m/e>0; e*=10) {
            countSort(arr, e, 10);
        }
        // return top k from arr from last
        int[] ans = new int[k];
        for (int j = 0; j < k; j++) {
            ans[j] = arr[arr.length-1-j][0];
        }
        return ans;
    }
    public static void main(String[] args) {
        TopKFrequent s = new TopKFrequent();
        int[] A = {1,1,1,2,2,3};
        int k = 2;
        System.out.println(Arrays.toString(s.topKFrequent(A, k)));
    }
}