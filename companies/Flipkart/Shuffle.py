from random import randrange
class ShuffleArray:
    def __init__(self,arr):
        self.arr = arr[:]
        self.original = arr[:]
    def shuffle(self): # shuffle inplace
        for i in range(len(self.arr)-1,0,-1):
            n = randrange(0,i+1)
            self.arr[n],self.arr[i]  =  self.arr[i],self.arr[n]
        return self.arr 
    def reset(self):
        self.arr = self.original[:]
        return self.arr
sf =ShuffleArray([1,2,3,4])
print(sf.reset())
print(sf.shuffle())