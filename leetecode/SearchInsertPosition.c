int searchInsert(int* nums, int numsSize, int target){
    int start = 0;
    int end = numsSize - 1;
    int mid=0;
    while (start<=end)
    {
        mid= (end+start)/2;
        if(target==nums[mid]){
            return mid;
        }
        if(nums[mid]>target){
            end=mid-1;
        }
        else{
            start = mid + 1;
        }

    }
    return nums[mid]<target ? mid+1 : mid;
    
}
void main(){
    int nums[10] = {1,4,5,7,8,10,12,13,16,18};
    printf("%d",searchInsert(nums,10,19));
}