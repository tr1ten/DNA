class Node:
    def __init__(self):
        self.childs = [None]*26
        self.ended = False
        self.index = -1

class Solution:
    def insert(self, word: str,idx:int) -> None:
        child = self.root
        if(word==word[::-1]): 
            child.ended = True
            child.index = idx
        for i,x in enumerate(word):
            ind = ord(x) - ord('a')
            if(child.childs[ind] is None): child.childs[ind]  = Node()
            child = child.childs[ind]
            if(i+1>=len(word) or word[i+1:]==word[i+1:][-1]):
                child.ended = True
                child.index = idx
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        self.root = Node()
        for i,w in enumerate(words): 
            self.insert(w[::-1],i)
        res = []
        for i in range(len(words)):
            child = self.root
            for j,x in enumerate(words[i]):
                ind = ord(x)-ord('a')
                child = child.childs[ind]
                if(not child): break
                if(child.ended and child.index!=i):
                    res.append([i,child.index])
        return res




        