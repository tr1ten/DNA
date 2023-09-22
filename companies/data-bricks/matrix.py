def solution(mat):
    res=(float('inf'),-1,-1)
    for r in range(len(mat)):
        for c in range(len(mat[0])):
            cnt = 0
            sm = 0
            for i in range(r+1):
                for j in range(c+1):
                    if mat[i][j]>=0: 
                        cnt+=1
                        sm +=mat[i][j]
            if(cnt==0): continue
            a1 = sm//cnt
            cnt = 0
            sm = 0
            
            for i in range(r+1,len(mat)):
                for j in range(c+1):
                    if mat[i][j]>=0:
                        cnt+=1
                        sm +=mat[i][j]
            if(cnt==0): continue
            a2 = sm//cnt
            
            cnt = 0
            sm = 0
            for i in range(0,r+1):
                for j in range(c+1,len(mat[0])):
                    if mat[i][j]>=0:
                        cnt+=1
                        sm +=mat[i][j]
            if(cnt==0): continue
            a3 = sm//cnt
            cnt = 0
            sm = 0
            for i in range(r+1,len(mat)):
                for j in range(c+1,len(mat[0])):
                    if mat[i][j]>=0:
                        cnt+=1
                        sm +=mat[i][j]
            
            if(cnt==0): continue
            a4 = sm//cnt
            val = max(a1,a2,a3,a4)-min(a1,a2,a3,a4)
            res = min((val,r,c),res)
    return res[1:]

mat = [
    [7,9,-1,-1],
    [3,8,-1,-1],
    [5,5,7,-1]
]
print(solution(mat))
