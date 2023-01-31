class Solution:
    def strongPasswordCheckerII(self, p: str) -> bool:
        if(len(p)<8): return False
        if(not any([(x in p) for x in string.ascii_lowercase])): 
           return False
        if(not any([(x in p) for x in string.ascii_uppercase])): return False
        if(not any([(x in p) for x in string.digits])): return False
        if(not any([(x in p )for x in "!@#$%^&*()-+"])): return False
        for i,x in enumerate(p):
           if(i+1<len(p) and p[i]==p[i+1]): return False
          
        return True