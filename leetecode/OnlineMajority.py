import bisect
import random
class MajorityChecker:

    def __init__(self, arr: List[int]):
        self.d = defaultdict(list)
        for i,x in enumerate(arr):
            self.d[x].append(i)
        self.a = arr
        

    def query(self, l: int, r: int, t: int) -> int:
        for x in range(30): # magic number, prob of incoress is less than 2^-40
            ind = random.randint(l,r)
            left = bisect.bisect_left(self.d[self.a[ind]],l)
            right = bisect.bisect_right(self.d[self.a[ind]],r)
            if(right-left>=t): return self.a[ind]
        return -1