int removeElement(int* nums, int numsSize, int val){
    int i = 0;
    int offset = 0;
    while (i<(numsSize-offset)){
        if(nums[i]==val){
            int temp = nums[numsSize-offset-1];
            nums[numsSize-offset-1] = nums[i];
            nums[i]=temp;
            ++offset;
        }
        else{
            ++i;
        }
    }
    return (numsSize-offset);

}
