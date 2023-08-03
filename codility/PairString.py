def solve(S):
    ms = [[-1]*26 for i in range(len(S[0]))]
    for i in range(len(S)):
        for j in range(len(S[0])):
            cur = ord(S[i][j]) - ord('a')
            if ms[j][cur]!=-1: return (i,ms[j][cur],j)
            else: ms[j][cur] = i
    return -1

S=input().split()
print(solve(S))