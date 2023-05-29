class TextEditor:
    def __init__(self):
        first = [-1,None,None]
        self.cur = first
    def __str__(self):
        temp  = self.cur
        while(temp and temp[1]):
            temp = temp[1]
        s = " List -> "
        while(temp):
            s += str(temp[0]) + " "
            if temp==self.cur: s+="* "
            temp = temp[2]
        return s
    def add(self,val):
        node = [val,None,None]
        nxt = self.cur[2]
        node[1] = self.cur
        node[2] = nxt
        if nxt: nxt[1] = node
        self.cur[2] = node
        self.cur = node

    def addText(self, text: str) -> None:
        for x in text: self.add(x)
        # print("added ",text,self)

    def deleteText(self, k: int) -> int:
        nxt = self.cur[2]
        cnt = self.move(k,1)
        self.cur[2] = nxt
        if nxt: nxt[1] = self.cur
        # print("after deleting ",k,self)
        return cnt

    def move(self,k,dir):
        cnt = 0
        while(self.cur[dir] and cnt<k):
            self.cur = self.cur[dir]
            cnt +=1
        return cnt
    def last(self):
        s = ""
        temp  =self.cur
        while(temp[0]!=-1 and len(s)<10):
            s += temp[0]
            temp = temp[1]
        return s[::-1]
    def cursorLeft(self, k: int) -> str:
        self.move(k,1)
        # print("left ",k,self)
        return self.last()

    def cursorRight(self, k: int) -> str:
        self.move(k,2)
        # print("right ",k,self)
        return self.last()
        