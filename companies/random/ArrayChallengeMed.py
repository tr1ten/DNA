class Node:
    def __init__(self):
        self.childs = [None]*26
        self.end = False
        self.val = ""
        
def stringChallenge(s):
    root = Node()
    words = {
        "zero":"0",
        "one":"1",
        "two":"2",
        "three":"3",
        "four":"4",
        "five":"5",
        "six":"6",
        "seven":"7",
        "eight":"8",
        "nine":"9",
        "minus": "-",
        "plus":"+"
    }
    rmap = dict(zip(words.values(), words.keys()))
    def insert(word):
        child = root
        for x in word:
            ind = ord(x) - ord('a')
            if(child.childs[ind] is None): child.childs[ind]  = Node()
            child = child.childs[ind]
        child.val = words[word]
        child.end = True
    for w in words: insert(w)
    child  = root
    res = ""
    for x in s:
        ind = ord(x)-ord('a')
        if(child.childs[ind].end):
            res += child.childs[ind].val
            child = root
        else: child = child.childs[ind]
        
    res = str(eval(res))
    res2 = ""
    for x in res:
        res2 += rmap[x]
    return res2;

print(stringChallenge("oneminusoneone"))
    
