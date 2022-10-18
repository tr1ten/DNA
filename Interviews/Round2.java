package Interviews;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

public class Round2 {
    double findAvg(int[] arr) {
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int maxCount = 1;
        int minCount = 1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
                maxCount = 1;
            } else if (arr[i] == max) {
                maxCount++;
            }
            if (arr[i] < min) {
                min = arr[i];
                minCount = 1;
            } else if (arr[i] == min) {
                minCount++;
            }
        }
        return (max*maxCount + min*minCount) / (double)(maxCount + minCount);
    }
    public static void main(String[] args) {
        Round2 r = new Round2();
        int[] arr = {1,4,3,4};
        System.out.println(r.findAvg(arr));
    }
}
