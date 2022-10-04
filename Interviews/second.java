package Interviews;

import java.util.Scanner;

public class second {
    // bitwise pair such that (A[i] | A[j]) - (A[i] & A[j]) = A[i] - A[j];
    void bitwisePair(int[] arr){
        int n = arr.length;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int temp = (arr[i] | arr[j]) - (arr[i] & arr[j]);
                if(temp>max) max = temp;
            }
        }
        System.out.println(max);
    }
    public static void main(String[] args) {
        //take input test case T with N array
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T>0) {
            int N = sc.nextInt();
            int[] arr = new int[N];
            for (int i = 0; i < N; i++) {
                arr[i] = sc.nextInt();
            }
            second obj = new second();
            obj.bitwisePair(arr);
            T--;
        }
    }
}
