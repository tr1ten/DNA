

def solve(k):
    ans = float('inf')
    res = [2]*20
    def brut(i,prod,sm,arr=[]):
        nonlocal ans,res
        if prod>ans:
            return 
        if prod>=sm+(k-i):
            if ans>prod or ( ans==prod and (len(arr)<len(res) or (len(arr)==len(res) and sorted(arr) < sorted(res)))):
                res = arr[::]
            ans = min(ans,prod)
            return
        for x in range(9,1,-1):
            arr.append(x)
            brut(i+1,prod*x,sm+x,arr)
            arr.pop()
    brut(0,1,0)  
    return "1"*(k-len(res)) + "".join(map(str,sorted(res)))

k = int(input())
print(solve(k))
