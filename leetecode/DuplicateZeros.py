class Solution:
    def duplicateZeros(self, arr) -> None:
        pointer = 0
        l = len(arr)
        while pointer < l:
            if arr[pointer] == 0:
                arr.insert(pointer, 0)
                pointer += 2
            else:
                pointer += 1
        del arr[l:]
        """
        Do not return anything, modify arr in-place instead.
        """
