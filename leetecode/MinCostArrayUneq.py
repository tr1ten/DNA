class Solution:
    def minimumTotalCost(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        freq = [0]*(n+1)
        mx_freq = 0;
        mx_val = -1;
        swaps = 0
        ans = 0
        for i in range(n):
            if(nums1[i]==nums2[i]):
                freq[nums1[i]] +=1
                if(freq[nums1[i]]>mx_val):
                    mx_val = nums1[i];
                mx_freq = max(mx_freq,freq[nums1[i]])
                swaps +=1
                ans +=i
        for i in range(n):
            if(mx_freq>swaps//2 and nums1[i]!=nums2[i] and nums1[i]!=mx_val and nums2[i]!=mx_val):
                swaps +=1
                ans +=i
        if(mx_freq>swaps//2): return -1
        return ans