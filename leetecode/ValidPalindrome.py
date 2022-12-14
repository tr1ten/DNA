# Don't blindly submit - first check for custom test cases 
# try to think of possibilities and edge cases
class Solution:
    def validPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s)-1
        lef = None
        rig = None
        flag = False
        def chk(p,q):
            while(p<q and s[p]==s[q]):
                p+=1
                q-=1
            return s[p]==s[q]
        while(j>i):
            if(s[j]!=s[i]):
                lef = i
                rig = j
                break
            i +=1
            j -=1
        if(lef==None): return True
        return chk(lef,rig-1) or chk(lef+1,rig) 