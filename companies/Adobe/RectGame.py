# https://leetcode.com/discuss/interview-question/3600386/Adobe-OA
import bisect
from collections import defaultdict
# generic binary index tree
class BIT:
    def __init__(self,n:int):
       self.nums = [0]*(n+1)
    def update(self,i:int,val:int):
        i +=1
        while(i<len(self.nums)):
            self.nums[i] +=val
            i += (i&(-i))
    def sum(self,i:int) -> int:
        r = 0
        i +=1
        while(i>0):
            r += self.nums[i]
            i -= (i&(-i))
        return r
"""
    Assume rectangle as points in 2d space,
    then question turns to find minimum size rectangle containg atleast k points.
    since distance is abs value, +dist + abs(-dist) adds up to 2x

"""
def solve(h:list[int],w:list[int],k:int):
    inds = sorted(range(len(h)),key=lambda x:w[x]) # sort based on x
    N = len(h)
    def ok(sz): # check if there exist a rectangle with side 2sz contain k points
        # map y indices to (0,m) for bit
        # find all y points we might need 
        to_id = defaultdict(int)
        for y in h:
            to_id[y] +=1 # point y
            to_id[y+sz] +=1  # point y+sz
            to_id[y-sz-1] +=1 # point y-sz-1
        id = 0 # map them to unique id
        for y in sorted(to_id.keys()):
            to_id[y] = id
            id +=1
        end,start,i = 0,0,0
        bit = BIT(id)
        while(i<N): # sliding window, assuming each point i as middle point in square of side 2*sz
            while(start<i and w[inds[start]]<w[inds[i]]-sz):
                bit.update(to_id[h[inds[start]]],-1) # remove old y's from bit
                start +=1
            while(end<N and w[inds[end]]<=w[inds[i]]+sz):
                bit.update(to_id[h[inds[end] ] ],+1) # add new y's
                end +=1
            if bit.sum(to_id[h[inds[i]]+sz] )-bit.sum(to_id[h[inds[i]]-sz-1] ) >=k: 
                return True # check total number of points from y-sz to y+sz 
            i+=1
        return False
    MAX = max(max(h),max(w))
    return bisect.bisect_left(range(0,MAX),True,key=ok) # binary search all possible value of side
    
H = list(map(int,input().split()))
W = list(map(int,input().split()))
k = int(input())
print(solve(H,W,k))

