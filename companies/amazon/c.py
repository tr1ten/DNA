def code(x):
    return ord(x)-ord('a')
def solve(old,new): # A old, B new
    def check(x,y): # old ,new 
        i = 0
        for a in y:
            if i<len(x) and (x[i]==a or code(x[i])==(code(a)+1)%26 ): i+=1
        return i==len(x)
    ans = []
    for x,y in zip(old,new):
        ans.append("YES" if check(x,y) else "NO")
    return ans
# 
print(solve(["abdbc","ach","abb"],["baacbab","accdb","baacba"]))
print(solve(["bdbf","aee"],["aaccbbee","aab"]))