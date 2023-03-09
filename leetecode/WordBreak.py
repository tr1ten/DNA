class Node:
    def __init__(self):
        self.childs = [None]*26
        self.ended  = False

class Solution:
    def add(self,word):
        node = self.root
        for i in range(len(word)):
            ind = ord(word[i])-ord('a')
            if(not node.childs[ind]):
                node.childs[ind] = Node()
            node = node.childs[ind]
        node.ended = True
    def wordBreak(self, s: str, words: List[str]) -> bool:
        self.root = Node()
        for w in words: self.add(w)
        dp  = [False]*(len(s)+1) # dp[i] - is s[i..n-1] possible?
        dp[-1] = True
        for i in range(len(s)-1,-1,-1):
            cur = self.root
            for j in range(i,len(s)):
                ind = ord(s[j]) - ord('a')
                if(not cur.childs[ind]): break
                cur = cur.childs[ind]
                if(cur.ended): dp[i] |=dp[j+1]
                
        print(dp)
        return dp[0]
        

