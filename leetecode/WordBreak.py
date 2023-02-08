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
    def _search(self,node,index,word):
        if(index>=len(word)): return node.ended
        if(node.ended and self._search(self.root,index,word)): return True
        ind = ord(word[index]) - ord('a')
        if(not node.childs[ind]): return False
        return self._search(node.childs[ind],index+1,word)
    def wordBreak(self, s: str, words: List[str]) -> bool:
        self.root = Node()
        for w in words: self.add(w)
        return self._search(self.root,0,s)
        

