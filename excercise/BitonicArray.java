package excercise;


// first increasing then descreasing - geek4geek
public class BitonicArray {
    private int _bitonicIndex(int[] arr)
    {
        int n = arr.length;
        if(n<3)
        {
            return 0;
        }
        int high = n-1;
        int low = 0;
        while(high>=low)
        {
            int mid = (high+low)/2;
            if(mid+1>=n || mid-1<0)
            {
                return mid;
            }
            boolean prev = arr[mid-1] < arr[mid];
            boolean next = arr[mid+1]>arr[mid];
            if(prev && next)
            {
                return mid;
            }
            if(prev && !next)
            {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
    // generic binary search for both asc and desc
    private boolean gBS(int[] arr,int low,int high,int k,Boolean asc)
    {
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(arr[mid]==k)
            {
                return true;
            }
            if(!asc || arr[mid]>k)
            {
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
    public boolean find(int k,int[] arr)
    {
        final int bin = _bitonicIndex(arr);
        if(bin==-1){
            throw new IllegalArgumentException();
        }
        if(k==arr[bin]) return true;
        if(k>arr[bin]) return false;
        return gBS(arr, 0, bin-1, k, true) || gBS(arr, bin+1, arr.length-1, k, false);
    }

    
}
