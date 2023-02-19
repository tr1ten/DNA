import math
class RangeQuery():
    
    def __init__(self,n) -> None:
        self.n = n
        self.slen = math.ceil(math.sqrt(n))
        self.sqrt = [0]*self.slen # range sum queries
        self.arr = [0]*n
    
    def update(self,idx,diff):
        sidx = idx//self.slen;
        self.arr[idx] +=diff
        self.sqrt[sidx] +=diff
    def rangeSum(self,l,r):
        res = 0
        while(l<=r):
            if(l%self.slen==0 and l+self.slen-1<=r):
                res += self.sqrt[l//self.slen]
                l += self.slen
            else:
                res += self.arr[l]
                l += 1
        return res
def main():
    rq = RangeQuery(10)
    for i in range(10):
        rq.update(i,i)
    print(rq.rangeSum(0,9)) # 45
    print(rq.rangeSum(0,4)) # 10
    
main()