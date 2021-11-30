class Solution:
    def reverse(self,x: int)->int:
        y = 0
        INT_MAX = 2**31
        t = abs(x)
        while (t!=0):
            y = y*10 + (t%10)
            if(y<-INT_MAX or y>=INT_MAX):
                return 0
            t //=10
        return -y if(x<0) else y