# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, t: int, m: 'MountainArray') -> int:
        pivot = bisect.bisect_left(range(0,m.length()-1),True,key=lambda i:m.get(i+1)<m.get(i))
        n1 = bisect.bisect_left(range(pivot+1),t,key=lambda x:m.get(x))
        n2 = bisect.bisect_left(range(pivot+1,m.length()),-t,key=lambda x:-m.get(x))
        l1,l2 = pivot+1,m.length()-pivot-1
        if n1>=l1 and n2>=l2: return -1
        if n1<l1 and m.get(n1)==t: return n1
        return pivot+1+n2 if n2<l2 and m.get(pivot+1+n2)==t else -1