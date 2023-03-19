class Node:
    def __init__(self):
        self.childs = defaultdict(Node)
        self.end = False
class WordDictionary:

    def __init__(self):
        self.root = Node()
        

    def addWord(self, word: str) -> None:
        child = self.root
        for x in word:
            ind = ord(x) - ord('a')
            child = child.childs[ind]
        child.end = True

    def search(self, word: str) -> bool:
        q = deque()
        q.append((0,self.root))
        while(q):
            ind,node = q.popleft()
            if(ind==len(word)): 
                if(node.end): return True
                continue
            if(word[ind]=='.'):
                for i in node.childs: 
                    if(ind+1==len(word) and node.childs[i].end): return True
                    q.append((ind+1,node.childs[i]))
            else:
                i = ord(word[ind]) - ord('a')
                if(i in node.childs): 
                    if(ind+1==len(word) and node.childs[i].end): return True
                    q.append((ind+1,node.childs[i]))
        return False

