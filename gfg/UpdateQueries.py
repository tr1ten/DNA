class Solution():
    def updateQuery(self, N, Q, U):
        N_BITS = 4
        das = [DifferenceArray(N) for i in range(N_BITS)]
        for l,r,v in U:
            for i in range(N_BITS):
                if((v&(1<<i))==0): continue
                das[i].update(l-1,r-1,1);
        arr = [0]*N
        for i in range(N_BITS):
            bit_arr = das[i].get();
            for j in range(N): 
                if(bit_arr[j]==0): continue
                arr[j] |= 1<<i
        return arr
class DifferenceArray:
    def __init__(self,n) -> None:
        self.da = [0]*n
    def update(self,l,r,val):
        self.da[l] +=val
        if(r+1<len(self.da)): self.da[r+1] -= val
    def get(self):
        arr = [0]*len(self.da)
        arr[0] = self.da[0]
        for i in range(1,len(self.da)):
            arr[i] = arr[i-1] + self.da[i]
        return arr
