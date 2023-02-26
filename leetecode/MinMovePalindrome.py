from collections import Counter
class Solution:
    def minMovesToMakePalindrome(self, s: str) -> int:
        ls = list(s)
        cnt = Counter(s)
        def swap(x,y):
            ls[x],ls[y] = ls[y],ls[x]
        res= 0 
        # greedily choose first half element whoever come first will get place if count >= 2
        for i in range((len(s))//2):
            j = i
            while(cnt[ls[j]]<2): j +=1
            while(j>i):
                swap(j-1,j)
                j -=1
                res +=1
            cnt[ls[i]] -= 2
        # need to put middle element in correct position
        if(len(s)%2==1):
            i = (len(s))//2
            j = i
            while(cnt[ls[j]]==0): j +=1
            while(j>i):
                swap(j-1,j)
                j -=1
                res +=1
            cnt[ls[i]] -= 1
        # place remaining element
        for i in range((len(s)+1)//2,len(s)):
            x = ls[len(s)-1-i]
            j=i
            while(ls[j]!=x): j+=1
            while(j>i):
                swap(j-1,j)
                j -=1
                res +=1
        return res


