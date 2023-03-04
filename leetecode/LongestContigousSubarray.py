class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        smaller = deque()
        larger = deque()
        j =0
        for i in range(len(nums)):
            while(larger and larger[-1]<nums[i]): larger.pop()
            while(smaller and smaller[-1]>nums[i]): smaller.pop()
            smaller.append(nums[i])
            larger.append(nums[i])
            if(larger[0]-smaller[0]>limit):
                if(nums[j]==larger[0]): larger.popleft()
                if(nums[j]==smaller[0]): smaller.popleft()
                j +=1
        return len(nums)-j