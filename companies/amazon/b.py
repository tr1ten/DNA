def solve(s):
    res = 0
    prev = None
    for x in s:
        if x!='?': 
            if prev and prev!=x: res+=1
            prev = x
    return res

print(solve("00?10??1?1"))
print(solve("??011??0"))
        