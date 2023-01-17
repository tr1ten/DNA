from collections import Counter
import heapq
class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int: 
        cnt = Counter([abs(nums1[i]-nums2[i]) for i in range(len(nums1))])
        gp = [(-k) for k in cnt]
        heapq.heapify(gp)
        k = k1+k2
        while(k>0 and gp):
            e = heapq.heappop(gp)
            e = -e
            v = cnt[e]
            if(e==0): break
            s = min(v,k)
            k -= s
            cnt[e] -=s
            if(v-s>0): 
                heapq.heappush(gp,(-e,v-s))
            if(e-1>0): 
                cnt[e-1] += s
                heapq.heappush(gp,(-(e-1),s))

            
        return sum([v*((-k)**2) for k,v in gp])
