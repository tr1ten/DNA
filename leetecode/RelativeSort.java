import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;

class Solution {
    public int[] relativeSortArray(int[] A, int[] arr2) {
        int[] cnt = new int[1001];
        HashSet<Integer> hs = new HashSet<>();
        for (int i = 0; i < A.length; i++) {
            cnt[A[i]]++; 
            hs.add(A[i]);
        } 
        int[] temp = new int[A.length];
        int k=0;
        for (int i = 0; i<arr2.length; i++) {
            hs.remove(arr2[i]);
            while (cnt[arr2[i]]>0) {
                temp[k++] = arr2[i];
                cnt[arr2[i]]--;
            }
        }
        List<Integer> sortedList = new ArrayList<>(hs);
        Collections.sort(sortedList);
        for (int i : sortedList) {
            while (cnt[i]>0) {
                temp[k++] = i;
                cnt[i]--;
            }
        }
        return temp;
    }
}