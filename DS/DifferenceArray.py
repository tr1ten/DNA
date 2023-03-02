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