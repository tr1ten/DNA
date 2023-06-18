def printer(s):
    res =0 
    cur = 0
    for x in s:
        nxt = ord(x) - ord('a')
        res += min(abs(cur-nxt),26-abs(cur-nxt))
        cur = nxt
    return res

while(1):
    print(printer(input()))