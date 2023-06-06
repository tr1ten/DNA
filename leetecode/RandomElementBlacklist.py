class Solution:

    def __init__(self, n: int, bb: List[int]):
        self.bs = {x:-1 for x in bb}
        self.m = n - len(self.bs) # self.m is number of whitelisted elements
        curr = self.m # we are just shifting blacklisted (remapping) <m value to >m values
        for x in bb: # so all elements >m will be blacklisted and lower than m will be whitelisted
            if x<self.m: 
                while(curr in self.bs): curr+=1
                self.bs[x] = curr
                curr+=1

    def pick(self) -> int:
        r = random.randrange(self.m)
        return self.bs[r] if r in self.bs else r # if blackliest value in random then change to white list



# Your Solution object will be instantiated and called as such:
# obj = Solution(n, blacklist)
# param_1 = obj.pick()