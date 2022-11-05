class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp = sorted(nums,reverse=True)
        k =0
        for i in range(1,len(nums),2):
            nums[i] = temp[k]
            k +=1
        for i in range(0,len(nums),2):
            nums[i] = temp[k]
            k +=1
        