def solve(A):
    st = []
    ans = 0
    mx = A[-1]
    for i in range(len(A)-1,-1,-1):
        while st and A[st[-1]]<=A[i]:
            st.pop()
        mx = max(mx,A[i])
        if st:
            ans = max(ans,mx-A[st[-1]])
        st.append(i)
    return ans
n = int(input())
A = list(map(int,input().split()))
print(solve(A))