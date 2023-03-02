class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        p = 0
        while(i<len(chars)):
            j = i
            while(j<len(chars) and chars[j]==chars[i]):  j+=1
            chars[p] = chars[i]
            p +=1
            if(j-i>1): 
                for k in str(j-i):
                    chars[p] = k
                    p+=1
            i = j
        return p
