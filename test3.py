
def solve(s:str):
    t = ""
    for x in s:
        if x!='i':
            t +=x
    s2 = t[:len(t)//2]
    if len(t)%2 or not s.endswith(s2):
        return "nopossible"
    return s[:len(s)-len(s2)]
    

print(solve("izizibibzzbb"))
    