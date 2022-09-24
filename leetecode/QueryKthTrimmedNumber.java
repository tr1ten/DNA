import java.util.HashMap;

class Solution {
    class Pair<T1,T2>{
        T1 first;
        T2 second;
        Pair(T1 first,T2 second){
            this.first = first;
            this.second = second;
        }
    }
    static Pair<String,Integer>[] countSort(Pair<String,Integer>[] A,int e,int k){
        int[] cnt = new int[k];
        for (int i = 0; i < A.length; i++) {
            cnt[A[i].first.charAt(e)-'0']++; 
        } 
        for (int i = 1; i < k; i++) {
            cnt[i] = cnt[i-1] + cnt[i];
        }
        Pair<String,Integer>[] temp = new Pair[A.length];
        for (int i = A.length-1; i>=0; i--) {
            temp[--cnt[A[i].first.charAt(e)-'0']] = A[i];
        }
        return temp;
    }
    public int[] smallestTrimmedNumbers(String[] nums, int[][] queries) {
        int d = nums[0].length();
        Pair<String,Integer>[][] mem = new Pair[d+1][nums.length];
        mem[0] = new Pair[nums.length];
        for (int i = 0; i < nums.length; i++) {
            mem[0][i] = new Pair(nums[i], i);
        }
        for (int i = d-1; i >=0; i--) {
            mem[d-i] = countSort(mem[d-i-1], i, 10);
        }
        int[] ans = new int[queries.length];
        int k=0;
        for (int[] q : queries) {
            ans[k++] = mem[q[1]][q[0]-1].second;
        }   
        return ans;
    }
}