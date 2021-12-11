int removeDuplicates(int* nums, int numsSize){
    if(numsSize<2){
        return numsSize;
    }
    int tail = 0;
    for(int i=0;i<numsSize;i++){
        if(nums[i] != nums[tail]){
            tail++;
            nums[tail] = nums[i];
            
            
        }
    }
    return tail+1;
    

}
