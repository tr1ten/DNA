def solve(par,al,wr):
    lines = []
    for i,p in enumerate(par):
        cur = 0
        ls = []
        for w in p:
            if cur+len(w)>wr:
                if al[i]=='LEFT':
                    lines.append("*" + " ".join(ls) + " "*(wr-cur) + "*" )
                else:
                    lines.append("*"+ " "*(wr-cur) + " ".join(ls) + "*")
                ls = []
                cur = 0
            ls.append(w)
            cur += len(w)+1 
        if al[i]=='LEFT':
            lines.append("*" + " ".join(ls) + " "*(wr-cur) + "*" )
        else:
            lines.append("*"+ " "*(wr-cur) + " ".join(ls) + "*")
    return lines

par = [["Hello","world"],["How","areYou",'Doing'],["PLease Look","and aligh","to right"]]
al = ["LEFT","RIGHT","RIGHT"]
w = 16
print(solve(par,al,w))