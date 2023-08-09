import sys


# input
t = int(sys.stdin.readline())
# solve here
def solve():
    x = input()
    res = [0] + list(map(int,x))
    last = len(res)
    carry = 0
    for i in range(len(res)-2,-1,-1):
        if res[i]==9: continue
        res[i] +=carry
        carry = 0
        if res[i+1]<5: continue
        if res[i]<9: res[i] +=1
        else: 
            carry+=1
            res[i] = 0
        last = i
    for i in range(last+1,len(res)): res[i] = 0
    print("".join(map(str,res)).lstrip("0") )
# input processing
for _ in range(t):
    solve()