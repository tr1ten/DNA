package Algos;

public class BinarySearch {
    public static int lower(int arr[],int key){
        int low = 0;
        int high = arr.length-1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(arr[mid] >= key){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
}
