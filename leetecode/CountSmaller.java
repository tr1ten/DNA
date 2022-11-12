import java.util.*;;
class Solution {
    Integer[] res;
    int[] im;
    void merge(int[] index,int l,int m,int r){
        int i=l;
        int j=m+1;
        int[] temp = new int[r-l+1];
        int k =0;
        while (i<=m && j<=r) {
            if(im[index[i]]>im[index[j]]){
                res[index[i]] += r-j+1;
                temp[k++] = index[i];
                i++;
            }
            else{
                temp[k++] = index[j];
                j++;
            }
        }
        while (i<=m) temp[k++] = index[i];    
        while (j<r) temp[k++] = index[j];
        k=0;
        for (int k2 = i; k2 <=j; k2++) {
            index[k2] = temp[k++];
        } 
    }
    void mergeSort(int[] nums,int l,int r){
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        res = new Integer[n];
        im = nums;
        int[] dmmy = new int[n];
        for (int i = 0; i < n; i++) {
            dmmy[i] = i;
        }
        mergeSort(dmmy, 0, n);
        return Arrays.asList(res);
    }
}