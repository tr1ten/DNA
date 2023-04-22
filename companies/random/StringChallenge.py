import string
def StringChallenge(st:str):
    p,t = st.split(" ")
    mem = dict()
    def f(i,j):
        if(i==len(p) and j==len(t)): return True
        if(i==len(p) or j==len(t)): return False
        key = (i,j)
        if(key in mem): return mem[key];
        x = p[i]
        c = t[j]
        if(x=="+"): 
            mem[key] = c.lower() in string.ascii_lowercase and f(i+1,j+1)
            return mem[key]
        if(x=="$"): 
            mem[key] = c.lower() in string.digits and f(i+1,j+1)
            return mem[key]
        if(x=="*"):
            times = 3
            _i = i+1
            if(i+3<len(p) and p[i+1]=="{"):
                times = int(p[i+2])
                _i = i+4
            if(j+times-1<len(t) and len(set(t[j:j+times]))==1): 
                mem[key] = f(_i,j+times)
                return mem[key]
        mem[key] = False
        return mem[key]
    return f(0,0)
        
print(StringChallenge("$**+*{2} 9mmmrrrkbb"))