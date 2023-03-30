class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        if(len(s1)==1): return True
        st1 = set()
        st2 = set()
        for i in range(len(s1)):
            st1.add(s1[i])
            st2.add(s2[i])
            if(st1==st2 and self.isScramble( s1[:i+1],s2[:i+1] )): 
                return True
        return False

            