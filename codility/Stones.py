def brut(state,zeros,idx):
    if idx==len(zeros): return 0
    res = float('inf')
    y,x = zeros[idx]
    for i in range(3):
        for j in range(3):
            if state[i][j]<=1: continue
            state[i][j] -=1
            res = min(res,abs(y-i) + abs(x-j) + brut(state,zeros,idx+1))
            state[i][j] +=1
    return res

A = []
zeros  = []
for i in range(3):
    A.append(list(map(int,input().split())))
    for j in range(3):
        if A[-1][j]==0: zeros.append((i,j))

print(brut(A,zeros,0))