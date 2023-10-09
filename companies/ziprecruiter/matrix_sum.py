from collections import defaultdict
def solve(mat,size):
    d = defaultdict(set)
    for i in range(len(mat) - size + 1):
        for j in range(len(mat[0]) - size+1):
            sm = 0
            st = set()
            for k in range(i,i+size):
                for l in range(j,j+size):
                    sm += mat[k][l]
                    st.add(mat[k][l])
            d[sm] |=st
    return sum(d[max(d.keys())])

mat = [
    [1,0,1,5,6],
    [3,3,0,3,3],
    [2,9,2,1,2],
    [0,2,4,2,0],
]
print(solve(mat,2))
