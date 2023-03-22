class Solution:
    def breakPalindrome(self, p: str) -> str:
        if(len(p)==1): return ""
        ls = list(p)
        for i in range(len(p)):
            if(ls[i]>'a' and i!=len(p)//2):
                ls[i] = 'a'
                break
        return "".join(ls)