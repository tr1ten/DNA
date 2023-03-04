class Bitset:

    def __init__(self, size: int):
        self.n = size
        self.arr  = [0]*size
        self.fc = 0
        self.zc = size

    def fix(self, idx: int) -> None:
        if(self.fc%2==0 and self.arr[idx]==1 or self.fc%2==1 and self.arr[idx]==0): return;
        self.arr[idx] = self.fc%2==0
        self.zc -=1

    def unfix(self, idx: int) -> None:
        if(self.fc%2==0 and self.arr[idx]==0 or self.fc%2==1 and self.arr[idx]==1): return;
        self.arr[idx] = self.fc%2==1         
        self.zc +=1

    def flip(self) -> None:
        self.fc +=1
        

    def all(self) -> bool:
        if(self.zc==self.n and self.fc%2==1): return True
        if(self.zc==0 and self.fc%2==0): return True
        return False

    def one(self) -> bool:
        if(self.zc==self.n and self.fc%2==0): return False
        if(self.zc==0 and self.fc%2==1): return False
        return True

    def count(self) -> int:
        print(self.arr,self.fc,self.n,self.zc)
        if(self.fc%2==0): return self.n-self.zc
        return self.zc

    def toString(self) -> str:
        res = ""
        for x in self.arr:
            res += str(x^(self.fc%2))
        return res


# Your Bitset object will be instantiated and called as such:
# obj = Bitset(size)
# obj.fix(idx)
# obj.unfix(idx)
# obj.flip()
# param_4 = obj.all()
# param_5 = obj.one()
# param_6 = obj.count()
# param_7 = obj.toString()