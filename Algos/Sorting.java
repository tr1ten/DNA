package Algos;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

/**
 * Sorting
 */
public class Sorting {

    @FunctionalInterface
    interface Indexer{
        double getVal(int i);
    }
    static void merge(int[] A,int p,int q,int r,Indexer ind){
        // merge A[p..q] and A[q+1..r]
        int n1 = q-p+1;
        int n2 = r-q;
        int[] temp = new int[n1+n2];
        int i=0;
        int j=0;
        int k=0;
        while(i<n1 && j<n2){
            if(ind.getVal(p+i)<ind.getVal(q+1+j)) temp[k++] = A[p+i++];
            else temp[k++] = A[q+1+j++];
        }
        while(i<n1) temp[k++] = A[p+i++];
        while(j<n2) temp[k++] = A[q+1+j++];
        for (int l = 0; l < temp.length; l++) {
            A[p+l] = temp[l];
        }
    }
    static void mergeSort(int[] A,int p,int r,Indexer ind){
        if(r<=p) return;
        int mid = (p+r)/2;
        mergeSort(A, p, mid,ind);
        mergeSort(A, mid+1, r,ind);
        merge(A,p,mid,r,ind);
    }
    static int max(int[] a){
        int max = Integer.MIN_VALUE;
        for(int i=0;i<a.length;i++){
            if(a[i]>max)
                max = a[i];
        }
        return max;
    }
    static int min(int[] a){
        int min = Integer.MAX_VALUE;
        for(int i=0;i<a.length;i++){
            if(a[i]<min)
                min = a[i];
        }
        return min;
    }
    static void countSort(int[] A,int e,int k){
        int[] cnt = new int[k];
        for (int i = 0; i < A.length; i++) {
            cnt[(A[i]/e)%k]++; 
        } 
        for (int i = 1; i < k; i++) {
            cnt[i] = cnt[i-1] + cnt[i];
        }
        int[] temp = new int[A.length];
        for (int i = A.length-1; i>=0; i--) {
            temp[--cnt[(A[i]/e)%k]] = A[i];
        }
        for (int i = 0; i < temp.length; i++) {
            A[i] = temp[i];
        }
    }
    static void radixSort(int[] A){
        int m = Math.max(A.length,max(A));
        for (int i = 1; i < m; i*=10) {
            countSort(A, i, 10);
        }
    }
    static void bucketSort(int[] A){
        int bs = 10; // bucket size
        int mn = min(A);
        double range =(max(A)-mn)*1.0/bs; // interpolating A
        ArrayList<Integer>[] buckets = new ArrayList[bs];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new ArrayList<>();
        }
        for (int a:A) {
            double bi = (a-mn)/range;
            if((bi-(int)bi)==0 && a!=mn){
                buckets[(int)bi-1].add(a);
            }
            else{
                buckets[(int)bi].add(a);
            }

        }
        int k=0;
        for (ArrayList<Integer> arrayList : buckets) {
            Collections.sort(arrayList);
            // copy to original array
            for (int i = 0; i < arrayList.size(); i++) {
                A[k++] = arrayList.get(i);
            }            
        }

    }
    static void testCount(){

        int[] A = {10,90,70,40,20,30,50,60,70,80,90};
        countSort(A, 10, 10);
        System.out.println(Arrays.toString(A));
    }
    static void testRadix(){
        int[] A = {1,6,4,32,10,213,123,1,11,23};
        radixSort(A);
        System.out.println(Arrays.toString(A));
    }
    static void testBucket(){
        int[] A = {9, 0, 10, 20, 0, 100, 5, 8, 4, 7};
        bucketSort(A);
        System.out.println(Arrays.toString(A));
    }
    // unit testing
    // write some test to test this sorting algo
    public static void main(String[] args) {
        // int[] A = {9,8,7,6,5,4,3,2,1};
        // mergeSort(A, 0, A.length-1);
        // System.out.println(Arrays.toString(A));
        // testCount();
        testBucket();
    }
}