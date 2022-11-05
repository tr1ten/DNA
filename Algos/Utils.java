package Algos;

import java.util.Arrays;

public class Utils {
    static int findFloor(long[] arr, int n, long x) {
        if (x >= arr[arr.length - 1]) {
            return arr.length - 1;
        }
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] > x) {
                if (mid != 0 && arr[mid - 1] < x) {
                    return mid;
                } else {
                    high = mid - 1;
                }
            } else {
                if (arr[mid] == x || (mid != 0 && arr[mid + 1] > x)) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            }
        }
        return -1;
    }
    // using Arrays.binarySearch
    static int findFloor2(long[] arr, long x) {
        int n = arr.length;
        if (x >= arr[arr.length - 1]) {
            return arr.length - 1;
        }
        int index = Arrays.binarySearch(arr, x);
        if (index < 0) {
            index = -index - 2;
        }
        else{
            while(index<n-1 && arr[index]==arr[index+1]) index++; 
        }
        return index;
    }
    public static void main(String[] args) {
        long[] arr = { 1, 2,2, 8, 10, 10, 12, 19 };
        long x = 2;
        int index = findFloor2(arr, 0);
        if (index == -1) {
            System.out.println("Floor of " + x + " doesn't exist in array ");
        } else {
            System.out.println("Floor of " + x + " is " + index);
        }
    }
}
