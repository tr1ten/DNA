package Algos;
// O(1) for range update using difference array
public class DiffferenceArray {
    int[] da;
    int[] old;
    DiffferenceArray(int n){
        da = new int[n];
    }
    DiffferenceArray(int[] nums){
        int n = nums.length;
        da = new int[n];
        da[0] = nums[0];
        for(int i=1;i<n;i++){
            da[i] = nums[i]-nums[i-1];
        }
        old = nums;
    }
    void update(int left,int right,int val){
        da[left] +=val;
        if(right+1<da.length) da[right+1] -= val;
    }
    int[] getArr(){
        int[] newArr = new int[old.length];
        // da[i] = nums[i] - nums[i-1]
        newArr[0] = da[0];
        for (int i = 1; i < newArr.length; i++) {
            newArr[i] = da[i] + newArr[i-1];
        }
        return newArr;
    }
    public static void main(String[] args) {
        int[] nums = {1,2,3,4,5,6,7,8,9,10};
        DiffferenceArray da = new DiffferenceArray(nums);
        da.update(0, 4, 10);
        da.update(4, 9, 10);
        int[] newArr = da.getArr();
        for (int i = 0; i < newArr.length; i++) {
            System.out.print(newArr[i]+" ");
        }
    }
}
