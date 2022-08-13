package Algos;

import java.util.Arrays;
import java.util.HashMap;

public class CountingSort {
    public static void main(String[] args) {
        int[] arr = {4,3,2,1};
        sort(arr, 0);
    }
    public static int[] sort(int[] arr, int k) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            String s = Integer.toString(arr[i]);
            int key = s.length() <= k ? 0 : s.charAt(k) - '0';
            if (hm.containsKey(key)) {
                hm.put(key, hm.get(key) + 1);
            } else {
                hm.put(key, 0);
            }
        }
        int[] sarr = {};
        int sk = 0;
        for (int i = 0; i < 10; i++) {
            if (hm.containsKey(i)) {
                Arrays.fill(sarr, sk, sk + hm.get(i), i);
                sk +=hm.get(i);
            }
        }
        return sarr;
    }
}
