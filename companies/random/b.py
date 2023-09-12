def solution(mat):
    st = []
    for i in range(len(mat)):
        for j in range(len(mat[0])):
            if mat[i][j]>0:
                st.append((mat[i][j],i,j))
    res = []
    st  = sorted(st,reverse=1)
    for d,i,j in st:
        f = 1
        for m,y,x in st:
            if(m<d): continue
            if(y==i and x==j): continue
            if i-d<=y<=i+d and j-d<=x<=j+d and (y,x) not in [(i-d,j-d),(i+d,j+d),(i+d,j-d),(i-d,j+d)]:
                f=0
                break
        if f: res.append((i,j))
    return res

mat = [
    [3,0,0,0,0],
    [0,0,1,0,0],
    [0,0,2,0,0],
    [0,0,0,0,0],
    [0,0,0,0,0],
    [0,3,0,0,3],
    
]
print(solution(mat))