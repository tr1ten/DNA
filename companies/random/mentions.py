from collections import Counter
def solve(members,messages):
    st = set(members)
    ans = Counter()
    for x in st: ans[x] = 0
    for m in messages:
        i = 0
        ids = []
        while i<len(m):
            if m[i]=='@':
                s = ""
                i+=1
                while i<len(m) and m[i]!=' ':
                    s += m[i]
                    i +=1
                ids.append(s)
            else: i+=1
        vis = set()
        for s in ids:
            for id in s.split(","):
                if id in st and id not in vis:
                    vis.add(id)
                    ans[id] +=1
    return [f'{x}={ans[x]}' for x in sorted(members,key=lambda x:-ans[x])]
print(solve(["id123","id234","id7","id321"],["Hey @id123,id321 re t","h @id7 nic app@och @id800 what ?","@id123,id321 thx!"]))
            
            