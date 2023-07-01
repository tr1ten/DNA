class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        ans = 0 # make bit by bit
        for i in range(32,-1,-1): # left to right because we want to ensure max bit is taken even if all lower bits not taken
            temp = ans>>i # select 32th...i  bits 
            pos = {x>>i for x in nums} # select same range for other btis as well
            if(any([temp^1^y in pos for y in pos] ) ): ans |=1<<i
        return ans