class Solution:
    def goodTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        mp = dict((x,y) for y,x in enumerate(nums2))
        res = 0
        n = len(nums1)
        for i in range(n):
            n1 = 0
            for j in range(i):
                if(mp[nums1[j]]<mp[nums1[i]]): n1 +=1
            n2 = 0
            for j in range(i+1,n):
                if(mp[nums1[j]]>mp[nums1[i]]): n2 +=1
            res += n1*n2
        return res