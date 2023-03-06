class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        lo = 0
        hi = len(arr)
        while(hi>lo):
            mid = (hi+lo)>>1
            if(arr[mid]-(mid+1)>=k): hi = mid
            else: lo = mid+1
        return k + lo