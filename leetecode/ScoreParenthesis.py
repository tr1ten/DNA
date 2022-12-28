class Solution:
    def scoreOfParentheses(self, s: str) -> int:
        op = [-1] # stores opened bracket indices
        data = [] # store data with indices of open
        for i,x in enumerate(s):
            if(x=='('): op.append(i)
            else:
                sm = 0
                while(len(data)>0 and op[-1]==data[-1][-1]):
                    sm += data.pop()[0]
                op.pop()
                if(sm==0): # if not nested
                    data.append((1,op[-1]))
                else:
                    data.append((2*sm,op[-1]))
        return sum([x[0] for x in data])
        