class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def solve(s1,s2):
            p1 = 0
            p2 = len(s2)-1
            # check for longest prefix of s1 which is a suffix of s2
            while(p1<p2 and s1[p1]==s2[p2]):
                p1+=1
                p2-=1
            # if all characters are same, then we can always make a palindrome
            if(p1>=p2): return True
            # check if the remaining part of s1(or s2) upto p2(inclusive) is a palindrome 
            return s1[p1:p2+1]==(s1[p1:p2+1])[::-1] or s2[p1:p2+1]==(s2[p1:p2+1])[::-1]
        return solve(a,b) or solve(b,a)