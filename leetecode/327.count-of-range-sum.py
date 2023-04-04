#
# @lc app=leetcode id=327 lang=python3
#
# [327] Count of Range Sum
#

# @lc code=start
from sortedcontainers import SortedList
class Solution:
    def countRangeSum(self, nums: List[int], l: int, u: int) -> int:
        sc = SortedList()
        sc.add(0);
        sm = 0
        res = 0
        for x in nums:
            sm +=x;
            lb = sm-u;
            up = sm-l;
            lf = sc.bisect_left(lb)
            rf = sc.bisect_right(up)
            res += rf-lf
            sc.add(sm)
        return res
        
        
        
# @lc code=end
class Solution:
    def countRangeSum(self, A: List[int], lb: int, ub: int) -> int:
        def ms(P,start,end): # merge while counting 
            if(end-start+1<=1): return 0
            mid = (start+end) >> 1
            count = ms(P,start,mid)+ms(P,mid+1,end) # sort left and right
            temp = []
            i=j=p = start
            for r in range(mid+1,end+1):
                while(i<mid+1 and P[i]<P[r]-ub): i+=1
                while(j<mid+1 and P[j]<=P[r]-lb): j+=1
                while(p<mid+1 and P[p]<=P[r]):
                    temp.append(P[p])
                    p +=1
                count += j-i
                temp.append(P[r])
            while(p<mid+1): 
                temp.append(P[p])
                p +=1
            i = start
            # print(start,end,count,P[start:end+1],temp)
            for x in temp:
                pref[i] = x
                i +=1
            return count
        pref = [0]
        for x in A: pref.append(pref[-1]+x)
        # print("before ", pref)
        ans = ms(pref,0,len(pref)-1)
        # print("after",pref)
        return ans
                
            
