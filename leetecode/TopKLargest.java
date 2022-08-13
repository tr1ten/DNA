package leetecode;

public class TopKLargest {
    private void swap(int[] arr,int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    private int partition(int high,int low,int[] arr){
        int pivot = arr[high];
        int p1 = low-1;
        for (int i = low; i < high; i++) {
            if(arr[i]<pivot){
                swap(arr,++p1,i);
            }
        }
        swap(arr,++p1,high);
        return p1;
    }
    public int findKthLargest(int[] nums, int k) {
        int high = nums.length-1;
        int low = 0;
        int target = (nums.length-k);
        while (low<=high){
            int part = partition(high,low,nums);
            if(part==target){
                return nums[part];
            }
            if(part<target) low = part+1;
            else high = part-1;
        }
        return 0;
    }

    public static void main(String[] args) {
//        [3,2,1,5,6,4], k = 2
        int[] nums = {3,2,1,5,6,4};
        var sol = new TopKLargest();
        System.out.println(sol.findKthLargest(nums,2));
    }
}
